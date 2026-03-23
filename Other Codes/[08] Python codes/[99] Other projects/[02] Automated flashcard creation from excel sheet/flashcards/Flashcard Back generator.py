import pandas as pd
from PIL import Image, ImageDraw, ImageFont
import os

os.chdir("D:\[03] Codes\[08] Python codes\[99] Other projects\[02] Automated flashcard creation from excel sheet")
# Paths
excel_file = "Flashcard data spreadsheet.xlsx"
output_dir = "flashcards_back"
template_image_path = "card_template.png"  # a blank template image
template_image = Image.open(template_image_path)
template_width, template_height = template_image.size

# Make sure output folder exists
os.makedirs(output_dir, exist_ok=True)

# Load Excel data
df = pd.read_excel(excel_file)
print(df.columns)
# Load a font

#definition_font = "C:\Windows\Fonts\CENTURY.TTF"
definition_font = ImageFont.truetype("C:\Windows\Fonts\segoeuib.ttf", size = 100)
synonym_font = ImageFont.truetype("C:\Windows\Fonts\segoeui.ttf", size = 70)
bold_synonym_font = ImageFont.truetype("C:\Windows\Fonts\segoeuib.ttf", size = 70)

def wrap_text(text ,  max_width, draw, font):
    lines = []
    words = text.split()
    current_line = ""
    test_line = ""

    for word in words:
        test_line = test_line + word + " "
        text_bounding_box = draw1.textbbox((0, 0), test_line, font = font)
        text_width = text_bounding_box[2] - text_bounding_box[0]

        if text_width <= max_width:
            current_line = test_line
            #print(current_line)
        else:
            lines.append(current_line)
            current_line = word + " "
            test_line = word + " "
    if current_line:
        lines.append(current_line)
    return lines
punctuations = '''''!()-[]{};:'"\,<>./?@#$%^&*_~'''
def remove_punctuation(text): 
     no_punctuation = ""
     for char in text:
          if char not in punctuations:
               no_punctuation = no_punctuation + char
     return no_punctuation
     
print("No punc: ", remove_punctuation("Hello! Let's have a _."))
# Loop through rows
for index, row in df.iterrows():
    word = row["Word "]
    definition = row["Definition "]
    definition =  "Def: " + definition
    #print(synonyms)

    img1 = Image.open(template_image_path).copy()
    draw1 = ImageDraw.Draw(img1)


###################### Definiton printing logic #################################################
    definition_bounding_box = draw1.textbbox((0, 0), definition, font = definition_font)

    definition_width = definition_bounding_box[2] - definition_bounding_box[0]
    definition_height = definition_bounding_box[3] - definition_bounding_box[1]
    text_x = 250
    text_y = 200
    
    #mytext = "I want to split this sentence into multiple parts which will fit in my card"
    wrapped_lines = wrap_text(text=definition, max_width = template_width - 400, draw = draw1, font = definition_font)
    #print(wrapped_lines)
    for line in wrapped_lines:
          draw1.text((text_x, text_y), line, font=definition_font, fill="#ff995b")
          text_y += (definition_height + 15 ) # line height + padding
    
    text_y  = max(text_y + 40, template_height /2 - 50)

###################### Synonym printing logic ##################################################
    draw1.text((text_x, text_y), "Syn: ", font=bold_synonym_font, fill="#000000")
    synonyms = row["Synonym 1"]  + ", " + row["Synonym 2"]

    test_synonyms = "Let's have a look at the world's most weird kind of synonym"

    synonym_bounding_box = draw1.textbbox((0, 0), definition, font = synonym_font)
    synonym_width = synonym_bounding_box[2] - synonym_bounding_box[0]
    definition_height = synonym_bounding_box[3] - synonym_bounding_box[1]


    wrapped_synonyms = wrap_text(text= test_synonyms, max_width = template_width - 550, draw = draw1, font = synonym_font)
    for line in wrapped_synonyms:
          draw1.text((text_x + 150, text_y), line, font=synonym_font, fill="#000000")
          text_y += definition_height  # line height + padding


###################### Example sentence printing logic ##################################################
    text_y+=30
    draw1.text((text_x, text_y), "Example: ", font=bold_synonym_font, fill="#000000")
    example = row["Example sentence 1"]
    example_sentence_words = example.split()
    print(example_sentence_words)
    sentence_parts = []
    key_words = [] # These are the instances of the keyword that is present in the sentence
                   # We are storing it because we might get the word in 3 main different format
                   # 1. Plain word with no capitalization and punctuation mark
                   # 2. Word having capitalization and no punctuation 
                   # 3. Word having punctuation but no capitalization 
                   # 4. Word having both punctuation and capitalization 

    # *There might be multiple key word in the sentence
    # *Some might be in the beginning with capital letter, some might be at the end with small letter
    #key_word = word
    key_word = "boy"
    key_word = key_word.lower() #making the word to lowercase
    current_part = ""

    print("key word = ", key_word)
    test_example_sentence = "Boy, I used to play with a black boy when I was a little boy."
    test_example_sentence_words = test_example_sentence.split()
    for words in test_example_sentence_words: 
         print(words)
         word = words # making a copy of the original word
         word = word.lower()
         word = remove_punctuation(word)

         if word == key_word: 
            #if current_part:
            print("current part = ", current_part)
            sentence_parts.append("++") # This thing marks that there's a word to be made bold here
            sentence_parts.append(current_part)
            current_part = ""
            key_words.append(words)
         else:
            current_part = current_part + " " +  words
    print("sentence parts = ", sentence_parts)
    print("key words = ", key_words)
    
                   
             
              
         

    



    img1_path = os.path.join(output_dir, f"{index+1}_word.png")
    img1.save(img1_path)


