# GnabarMultiThread runs multiple simulations concurently for collecting data

import sys
import subprocess
import time
import math
import os
import consts

start = time.clock()

my_file = os.path.join(consts.PY_SCRIPTS_FOLDER, 'ThresholdExperiment.py')

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