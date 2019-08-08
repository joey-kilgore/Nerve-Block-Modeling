# This is the script instantiated from GnabarMultiThread.py
import sys
import os
import neuron
import consts

gnabarValue = round(float(sys.argv[1]),2)
processId = int(sys.argv[2])

my_file = os.path.join(consts.PY_SCRIPTS_FOLDER, 'file'+str(processId)+'.csv')

sys.stdout = open(my_file, 'w')
print('Gnabar value,' + str(gnabarValue))

h = neuron.hoc.HocObject()

h('nrn_load_dll("{}")'.format(consts.NRNMECH_DLL))
h('load_file("{}")'.format(consts.CNOW_RUN_HOC))

hocCommand = "changeGnabarFromCenter(" + str(gnabarValue) + ")"

h(hocCommand)