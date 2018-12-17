import sys
import neuron
import threading

lowerBound = int(sys.argv[1])
upperBound = int(sys.argv[2])
resolution = int(sys.argv[3])

h = neuron.hoc.HocObject()

h('chdir("C:/Users/Joey/Desktop/Stuff/Code/NEURON/Current Simulation/")')
h('getcwd()')
h('nrn_load_dll("nrnmech.dll")')
h('load_file("CNOW_run.hoc")')

hocCommand = "runTestAcrossParams(" + str(lowerBound) + "," + str(upperBound) + "," + str(resolution) + ",8000,9000,500)"

h(hocCommand)