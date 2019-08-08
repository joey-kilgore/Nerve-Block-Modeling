import sys
import subprocess
import time
import math
import os
import consts

start = time.clock()

my_file = os.path.join(consts.PY_SCRIPTS_FOLDER, 'WaveformComparisonExperiment.py')

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