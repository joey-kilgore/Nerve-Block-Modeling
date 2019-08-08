#!/usr/bin/env python3
# GnabarMultiThread runs multiple simulations concurently for collecting data
import sys
import subprocess
import time
import math
import os

start = time.clock()

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'ThresholdExperiment.py')

procs = []
numProcesses = 5
rangePerThread = 2000
for i in range(numProcesses):
    argList = [str(5000+(i*(rangePerThread+1000))),str(rangePerThread) , str(i)]
    proc = subprocess.Popen(['python', my_file] + argList)
    procs.append(proc)



for proc in procs:
    proc.wait()

stop = time.clock()

print(stop - start)