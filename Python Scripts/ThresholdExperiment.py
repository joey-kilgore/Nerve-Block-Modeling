# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron
import consts

startingFreq = int(sys.argv[1])
freqRange = int(sys.argv[2])
processId = int(sys.argv[3])

my_file = os.path.join(consts.PY_SCRIPTS_FOLDER, 'file'+str(processId)+'.csv')

sys.stdout = open(my_file, 'w')

h = neuron.hoc.HocObject()

h('nrn_load_dll("{}")'.format(consts.NRNMECH_DLL))
h('load_file("{}")'.format(consts.CNOW_RUN_HOC))
h('waveform_sel(1)')
h('setoffset(0)')
h('onset1 = 10')
h('dur1 = 300')
h('sinestim()')
#h('changeDiam(7)')
h('setStim(10,40,.1)')

h('changeModel(0)') # set MRG MODEL
print("MRG MODEL!!!")
for i in range(startingFreq,startingFreq+freqRange+1000,1000):
    print('FREQUENCY,'+str(i))
    h('freq = '+str(i))
    h('sinestim()')
    h('findThreshold(450000,650000,0,10,50,.1,1,1000)')

h('insert_cf()') # set freq-dep MRG MODEL
print("FREQUENCY-DEPENDENT MRG MODEL!!!")
for i in range(startingFreq,startingFreq+freqRange+1000,1000):
    print('FREQUENCY,'+str(i))
    h('freq = '+str(i))
    h('sinestim()')
    h('findThreshold(450000,650000,0,10,50,.1,1,1000)')