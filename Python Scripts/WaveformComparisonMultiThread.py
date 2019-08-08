#!/usr/bin/env python3
import sys
import subprocess
import time
import math
import os

start = time.clock()

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'WaveformComparisonExperiment.py')

procs = []
numProcesses = 5
rangePerThread = 2000
for i in [1,3,5,7,8]:
    argList = [str(i)]
    proc = subprocess.Popen(['python', my_file] + argList)
    procs.append(proc)

for proc in procs:
    proc.wait()

stop = time.clock()

print(stop - start)