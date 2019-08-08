# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron
import consts

processId = 0

my_file = os.path.join(consts.PY_SCRIPTS_FOLDER, 'file'+str(processId)+'.csv')

sys.stdout = open(my_file, 'w')
print('GAP TIME TEST')

h = neuron.hoc.HocObject()

h('nrn_load_dll("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
h('load_file("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')

dcAmp = -600000
freq = 10000
numTrials = 40
for i in range(numTrials):
    hfAmp = 400000 + (400000/numTrials)*i
    hocCommand = 'findMaxGap('+str(dcAmp)+','+str(hfAmp)+','+str(freq)+')'
    h(hocCommand)