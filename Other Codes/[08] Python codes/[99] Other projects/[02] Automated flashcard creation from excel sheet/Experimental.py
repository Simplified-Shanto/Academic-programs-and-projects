import os
import matplotlib.font_manager as fm

font_paths = fm.findSystemFonts(fontpaths=None, fontext='ttf')

for path in font_paths:
    print(path)
