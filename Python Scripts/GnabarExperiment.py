# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron

gnabarValue = round(float(sys.argv[1]),2)
processId = int(sys.argv[2])

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
my_file = os.path.join(THIS_FOLDER, 'file'+str(processId)+'.csv')

sys.stdout = open(my_file, 'w')
print('Gnabar value,' + str(gnabarValue))

h = neuron.hoc.HocObject()

h('nrn_load_dll("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/models/nrnmech.dll")')
h('load_file("C:/Users/Joey/Desktop/Stuff/Code/Nerve-Block-Modeling/Current Simulation/CNOW_run.hoc")')

hocCommand = "changeGnabarFromCenter(" + str(gnabarValue) + ")"

h(hocCommand)