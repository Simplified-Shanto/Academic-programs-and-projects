from PIL import Image
from PIL import ImageFilter
from PIL import ImageFont
from PIL import ImageDraw
import os
os.chdir(r"D:\[03] Codes\[08] Python codes\[02] Other projects\[01] Batch image watermark project")


inPath = r"D:\[03] Codes\[08] Python codes\[02] Other projects\[01] Batch image watermark project\Graphics"
outPath = r"D:\[03] Codes\[08] Python codes\[02] Other projects\[01] Batch image watermark project\Generated Images"



for imagePath in os.listdir(inPath):
    inputPath = os.path.join(inPath, imagePath)
    
    img = Image.open(inputPath)
    # Image is converted into editable form using
    # Draw function and assigned to draw
    draw = ImageDraw.Draw(img)
    w, h = img.size
    font = ImageFont.truetype("arial.ttf", w/15)

    # Decide the text location, color and font
    # (0, 0, 0) - Black color text
    try:
        fullOutPath = os.path.join(outPath, 'water_marked_'+imagePath)
        text = "Neverland Restaurant"
        draw.text((30, 30), text, fill = "green", font = font, align = "left")
        img.save(fullOutPath)
    except:
        print(f"Couldnt't show {imagePath}")
    
    # print(fullOutPath)