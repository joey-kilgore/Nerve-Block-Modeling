#!/usr/bin/env python3

import sys
import neuron
import threading

lowerBound = int(sys.argv[1])
upperBound = int(sys.argv[2])
resolution = int(sys.argv[3])

h = neuron.hoc.HocObject()

h('nrn_load_dll(""C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
h('load_file(""C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')

hocCommand = "runTestAcrossParams(" + str(lowerBound) + "," + str(upperBound) + "," + str(resolution) + ",8000,9000,500)"

h(hocCommand)