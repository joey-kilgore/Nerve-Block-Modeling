import sys
import neuron
import threading
import consts

lowerBound = int(sys.argv[1])
upperBound = int(sys.argv[2])
resolution = int(sys.argv[3])

h = neuron.hoc.HocObject()

h('nrn_load_dll("{}")'.format(consts.NRNMECH_DLL))
h('load_file("{}")'.format(consts.CNOW_RUN_HOC))

hocCommand = "runTestAcrossParams(" + str(lowerBound) + "," + str(upperBound) + "," + str(resolution) + ",8000,9000,500)"

h(hocCommand)