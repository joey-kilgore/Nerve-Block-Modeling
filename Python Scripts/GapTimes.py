#!/usr/bin/env python3
# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron

processId = 0

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'file'+str(processId)+'.csv')

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