# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron

startingFreq = int(sys.argv[1])
freqRange = int(sys.argv[2])
processId = int(sys.argv[3])

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'file'+str(processId)+'.csv')

sys.stdout = open(my_file, 'w')

h = neuron.hoc.HocObject()

h('nrn_load_dll("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
h('load_file("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')
h('waveform_sel(1)')
h('setoffset(0)')
h('onset1 = 10')
h('dur1 = 300')
h('sinestim()')

h('changeModel(0)') # set MRG MODEL
print("MRG MODEL!!!")
for i in range(startingFreq,startingFreq+freqRange+1000,1000):
    print('FREQUENCY,'+str(i))
    h('dt='+str(1/(i/1000)/12)) # set dt to 1/12 the length of one period
    h('setdt()')
    h('freq = '+str(i))
    h('sinestim()')
    h('findThreshold(500000,750000,0,10,50,.1,1,1000)')

h('changeModel(2)') # set freq-dep MRG MODEL
print("FREQUENCY-DEPENDENT MRG MODEL!!!")
for i in range(startingFreq,startingFreq+freqRange+1000,1000):
    print('FREQUENCY,'+str(i))
    h('dt='+str(1/(i/1000)/12)) # set dt to 1/12 the length of one period
    h('setdt()')
    h('freq = '+str(i))
    h('sinestim()')
    h('findThreshold(500000,750000,0,10,50,.1,1,1000)')