#!/usr/bin/env python3
# GnabarMultiThread runs multiple simulations concurently for collecting data
import sys
import subprocess
import time
import math
import os

start = time.clock()

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'GnabarExperiment.py')

procs = []
numProcesses = 5
lowerGnabar = 2.7   # starting test value for gnabar
incrementGnabar = .15 # the increment of gnabar between multiple tests
for i in range(numProcesses):
    argList = [str(lowerGnabar + i*incrementGnabar), str(i)]
    proc = subprocess.Popen(['python', my_file] + argList)
    procs.append(proc)



for proc in procs:
    proc.wait()

stop = time.clock()

print(stop - start)