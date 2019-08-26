import neuron

h = neuron.hoc.HocObject()
processId = 3
def hocSetup():
    global processId
    # Load NEURON with all the models and procedures normally available
    h('nrn_load_dll("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
    h('load_file("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')
    # Fiber diameter varies across each process
    setDiamCommand = "changeDiam(" + str(processId) + ")"
    print(setDiamCommand)
    h(setDiamCommand)
    h('setStim(10,40,.1)')
    h('insert_cf()') # set freq-dep MRG MODE

def testGaps():
    h('turnOnCustomElectrodes()')
    h('createElectrode(2,0,1000)')
    
    # loop through gap times and find the block threshold
    for gapTime in (0, 0.1, 0.12, 0.13, 0.14, 0.15):
        print('GAP TIME (ms), '+str(gapTime))
        # set gap post cathod (post high)
        h('electrodes[0].electrodeModel.postcathod_dur ='+str(gapTime))
        # set gap post anod (post low)
        h('electrodes[0].electrodeModel.postanod_dur ='+str(gapTime))
        h('findThreshold(200000,1500000,0,10,50,.1,1,1000)')

hocSetup()
testGaps()