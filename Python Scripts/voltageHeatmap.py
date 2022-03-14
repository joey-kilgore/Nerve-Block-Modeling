from PIL import Image, ImageDraw
# https://code-maven.com/create-images-with-python-pil-pillow
#img = Image.new(mode,size,color)
img = Image.new('RGB', (101,13000), color='#FFFFFF')
draw = ImageDraw.Draw(img)

# for i in range(0,50,2):
#     draw.point((i,15),fill='blue')


import csv
import math
#"D:\TestData\CROW\Best Trials CROW\DCAmpComparison\trial7\Voltage.csv"
with open("L:\\Work\\Manuscripts\\CROW Relay Paper 2\\state-data\\singleCathode\\Voltage.csv") as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        for node in range(1,101,1):
            colorVal = math.floor(float(row[node])+250)
            draw.line(((node-1),(line_count),(node),(line_count)), fill=colorVal, width=1)
        line_count += 1
        if line_count%500==0:
            print(f'Line {line_count}')

img.save('voltage.png')