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

def hocSetup():
    h('nrn_load_dll("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
    h('load_file("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')
    # Fiber diameter varies across each process
    setDiam = 'changeDiam(' + str(processId+3) + ')'
    h(setDiam)
    h('setStim(10,40,.1)')
    h('changeModel(0)') # set MRG MODEL
    h('insert_cf()') # set freq-dep MRG MODEL

def sineWaveTest():
    h('waveform_sel(1)')
    h('onset1 = 10')
    h('dur1 = 300')
    h('setoffset(0)')
    h('sinestim()')
    print("SINE WAVE")
    h('run()')
    # for i in range(startingFreq,startingFreq+freqRange+1000,1000):
    #     print('FREQUENCY,'+str(i))
    #     h('freq = '+str(i))
    #     h('sinestim()')
    #     h('findThreshold(450000,650000,0,10,50,.1,1,1000)')

def triWaveTest():
    h('waveform_sel(2)')
    h('amp1 = 1500000')
    h('onset1 = 10')
    h('dur1 = 300')
    h('offset = 0')
    h('tristim()')
    print("TRIANGLE WAVE")
    h('run()')
    # for i in range(startingFreq,startingFreq+freqRange+1000,1000):
    #     print('FREQUENCY,'+str(i))
    #     h('freq = '+str(i))
    #     h('sinestim()')
    #     h('findThreshold(450000,650000,0,10,50,.1,1,1000)')

def squareWaveTest():
    h('waveform_sel(0)')
    # Set the square wave params to match the frequency
    frequency = 10 #kHz
    cathodDuration = 1/frequency/2
    setCathodDur = 'cathod_dur=' + str(cathodDuration)
    setPostCathodDur = 'postCathod_dur=0'
    setAnodDur = 'anod_dur=' + str(cathodDuration)
    setPostAnodDur = 'postAnod_dur=0'
    h(setCathodDur)
    h(setPostCathodDur)
    h(setAnodDur)
    h(setPostAnodDur)
    h('high_amp1 = 500000')
    h('bal_val1()')
    h('run()')

hocSetup()
sineWaveTest()
triWaveTest()
squareWaveTest()