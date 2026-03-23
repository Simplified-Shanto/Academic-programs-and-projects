import pandas as pd
from PIL import Image, ImageDraw, ImageFont
import os


os.chdir("D:\[03] Codes\[08] Python codes\[99] Other projects\[02] Automated flashcard creation from excel sheet")
# Paths
excel_file = "Flashcard data spreadsheet.xlsx"
output_dir = "flashcards"
template_image_path = "card_template.png"  # a blank template image
template_image = Image.open(template_image_path)
template_width, template_height = template_image.size

# Make sure output folder exists
os.makedirs(output_dir, exist_ok=True)

# Load Excel data
df = pd.read_excel(excel_file)
#print(df.columns)
# Load a font
font_path = "C:\Windows\Fonts\comic.ttf" 
font = ImageFont.truetype(font_path, size=250)


#font_path1 = "C:\Windows\Fonts\CENTURY.TTF"
font_path1 = "C:\Windows\Fonts\segoeui.ttf"
font1 = ImageFont.truetype(font_path1, size = 100)
# Loop through rows
for index, row in df.iterrows():
    word = row["Word "]
    definition = row["Definition "]
    example = row["Example sentence 1"]

    
    # print(word, " ", definition, " ", example)
    #print(word)

    # # -------- Flashcard 1: Word Only --------
    img1 = Image.open(template_image_path).copy()
    draw1 = ImageDraw.Draw(img1)
    text_boundingbox = draw1.textbbox((0, 0), word, font = font)

    text_width = text_boundingbox[2] - text_boundingbox[0]
    text_height = text_boundingbox[3] - text_boundingbox[1]

    center_x = template_width/2
    center_y = template_height/2

    text_x = center_x - text_width/2
    text_y = center_y  - text_height/2 - 50


    draw1.text((center_x - 130, 340), "Define", font = font1, fill = "#ff995b")
    draw1.text((text_x , text_y ), word, font=font, fill="black")
    img1_path = os.path.join(output_dir, f"{index+1}_word.png")
    img1.save(img1_path)

    # # -------- Flashcard 2: Definition + Example --------
    # img2 = Image.open(template_image_path).copy()
    # draw2 = ImageDraw.Draw(img2)
    # text = f"{definition}\n\nExample: {example}"
    # draw2.text((100, 100), text, font=font, fill="black")
    # img2_path = os.path.join(output_dir, f"{index+1}_meaning.png")
    # img2.save(img2_path)
