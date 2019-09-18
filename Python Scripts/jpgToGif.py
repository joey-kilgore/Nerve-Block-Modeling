# using convert through Python
import subprocess
import os
import glob
import moviepy.editor as mpy

os.chdir("D:\\Raw Data\\dtaffect\\plots\\Point Plots with extra nodes\\ppms400")
print("Working Directory: ",os.getcwd())

gif_name = 'outputName'
fps = 12
file_list = glob.glob('*.png') # Get all the pngs in the current directory
list.sort(file_list, key=lambda x: int(x.split('.')[0].split('.png')[0])) # Sort the images by #, this may need to be tweaked for your use case
clip = mpy.ImageSequenceClip(file_list, fps=fps)
clip.write_gif('{}.gif'.format(gif_name), fps=fps)