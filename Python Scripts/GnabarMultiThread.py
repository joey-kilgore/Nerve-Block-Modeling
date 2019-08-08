# GnabarMultiThread runs multiple simulations concurently for collecting data

import sys
import subprocess
import time
import math
import os
import consts

start = time.clock()

my_file = os.path.join(consts.PY_SCRIPTS_FOLDER, 'GnabarExperiment.py')

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