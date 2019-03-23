# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron

processId = int(sys.argv[1])

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'file'+str(processId)+'.csv')

sys.stdout = open(my_file, 'w')

h = neuron.hoc.HocObject()

def hocSetup():
    global processId
    h('nrn_load_dll("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
    h('load_file("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')
    # Fiber diameter varies across each process
    setDiam = 'changeDiam(' + str(processId+4) + ')'
    h(setDiam)
    h('setStim(10,40,.1)')
    h('insert_cf()') # set freq-dep MRG MODEL

def setHocTimeStep(frequency):
    # Set time step value to be 1/12 the period, or smaller
    if frequency <= 15:
        h('steps_per_ms = 200')
        h('dt = .005')
        print('dt,.005')
    elif frequency <= 20:
        h('steps_per_ms = 250')
        h('dt = .004') 
        print('dt,.004')
    elif frequency <= 40:
        h('steps_per_ms = 500')
        h('dt = .002')
        print('dt,.002')
    elif frequency <= 80:
        h('steps_per_ms = 1000')
        h('dt = .001')
        print('dt,.001')

def sineWaveTest():
    h('waveform_sel(1)')
    h('onset1 = 10')
    h('dur1 = 300')
    h('setoffset(0)')
    h('sinestim()')
    print("SINE WAVE")

    # Find 10kHz Block
    print('FREQUENCY,'+str(10000))
    h('freq = '+str(10000))
    h('sinestim()')
    setHocTimeStep(10)
    h('block10kHz = findThreshold(301000,600000,0,10,50,.1,1,1000)')
    # Find 60kHz Block
    print('FREQUENCY,'+str(60000))
    h('freq = '+str(60000))
    h('sinestim()')
    setHocTimeStep(60)
    h('block60kHz = findThreshold(501000,800000,0,10,50,.1,1,1000)')
    block10 = h.block10kHz
    block60 = h.block60kHz

    for i in range(15,60,5):
        print('FREQUENCY,'+str(i*1000))
        h('freq = '+str(i*1000))
        h('sinestim()')
        setHocTimeStep(i)
        minAmp = (block60-block10)/50000*i*1000+(block10-(block60-block10)/(50000)) - 100000
        maxAmp = minAmp + 200000
        print("MIN AMP,"+str(minAmp))
        print("MAX AMP,"+str(maxAmp))
        command = 'findThreshold('+str(minAmp)+','+str(maxAmp)+',0,10,50,.1,1,1000)'
        h(command)


def triWaveTest():
    h('waveform_sel(2)')
    h('amp1 = 1500000')
    h('onset1 = 10')
    h('dur1 = 300')
    h('offset = 0')
    h('tristim()')
    print("TRIANGLE WAVE")
    # Find 10kHz Block
    print('FREQUENCY,'+str(10000))
    h('freq = '+str(10000))
    h('tristim()')
    setHocTimeStep(10)
    h('block10kHz = findThreshold(500000,1000000,0,10,50,.1,1,1000)')
    # Find 60kHz Block
    print('FREQUENCY,'+str(60000))
    h('freq = '+str(60000))
    h('tristim()')
    setHocTimeStep(60)
    h('block60kHz = findThreshold(600000,2000000,0,10,50,.1,1,1000)')
    block10 = h.block10kHz
    block60 = h.block60kHz

    for i in range(15,60,5):
        print('FREQUENCY,'+str(i*1000))
        h('freq = '+str(i*1000))
        h('sinestim()')
        setHocTimeStep(i)
        minAmp = (block60-block10)/50000*i*1000+(block10-(block60-block10)/(50000)) - 100000
        maxAmp = minAmp + 200000
        print("MIN AMP,"+str(minAmp))
        print("MAX AMP,"+str(maxAmp))
        command = 'findThreshold('+str(minAmp)+','+str(maxAmp)+',0,10,50,.1,1,1000)'
        h(command)

def squareWaveTest():
    h('waveform_sel(0)')
    # Set the square wave params to match the frequency
    frequency = 10
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
triWaveTest()