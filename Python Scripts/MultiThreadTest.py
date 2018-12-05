import sys
import subprocess

procs = []
for i in range(5):
    lowBound = i*100000
    upperBound = lowBound + 50000
    resolution = 50000
    argList = [str(lowBound), str(upperBound), str(resolution)]
    proc = subprocess.Popen(['python', 'C:/Users/Joey/Desktop/Stuff/Code/Python/RunHoc.py'] + argList)
    procs.append(proc)

for proc in procs:
    proc.wait()