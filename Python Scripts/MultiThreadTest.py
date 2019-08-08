import sys
import subprocess
import time
import math
import consts

def roundDownToRes(num, res):
    return res * math.floor(num/res)

def roundUpToRes(num, res):
    return res * math.ceil(num/res)

start = time.clock()

procs = []
numProcesses = 6
maxBound = 300000
minBound = 0
resolution = 10000

for i in range(numProcesses):
    upperBound = roundDownToRes((maxBound - minBound)/numProcesses * (i+1), resolution) + minBound
    lowerBound = roundUpToRes((maxBound - minBound)/numProcesses * i, resolution) + minBound
    argList = [str(lowerBound), str(upperBound), str(resolution)]
    proc = subprocess.Popen(['python', consts.RUNHOC_PY] + argList)
    procs.append(proc)



for proc in procs:
    proc.wait()

stop = time.clock()

print(stop - start)