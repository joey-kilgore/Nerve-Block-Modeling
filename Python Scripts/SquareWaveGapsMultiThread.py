import os
import subprocess
import time

start = time.clock()    # Track duration for the entire simulation

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'SquareWaveGapsExperiment.py')

numProcesses = 3
procs = []

# Create a child process for each different process number
for i in [2,3,4,5]:
    argList = [str(i)]
    proc = subprocess.Popen(['python', my_file] + argList)
    procs.append(proc)

# Wait for all child processes to finish before giving the duration of the simulation
for proc in procs:
    proc.wait()

stop = time.clock()
print(stop - start)