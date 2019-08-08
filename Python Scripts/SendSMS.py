#!/usr/bin/env python3
# First email input is needed to send the text to the user
# The text is sent by using email, and it is assumed the user has a verizon phone number
# Note that raw_input was renamed to input in Python 3

# because the same email and password are always used, they can be hard coded
email = 'alertsimulation@gmail.com'
password = '@lertSimulation1'

phoneNumber = input('Input Verizon phone number : ')
send_to_email = phoneNumber + '@vtext.com'

# workingDir = input('Input working directory for simulations : ')
workingDir = "C:/Users/Joey/Desktop/Stuff/Code/NEURON/Current Simulation/"
setWorkingDir = 'chdir("' + workingDir + '")'
print(setWorkingDir)
# Run the neuron simulations
from neuron import h, gui
h(setWorkingDir)
h('nrn_load_dll("nrnmech.dll")')
h('load_file("CNOW_run.hoc")')

import sys
oldstdout = sys.stdout
sys.stdout = open('C:/Users/Joey/Desktop/simulationOutput.csv', 'w')

hocCommand = "findThreshold(400000,600000,0,10,50,.1,1,1000)"
h(hocCommand)

sys.stdout = oldstdout

file = open('C:/Users/Joey/Desktop/simulationOutput.csv', 'r')
output = file.readlines()
file.close()
print(output)

import smtplib

# Need a newline character or python is confused what the colon is
message = '\nYour simulation completed and returned : '
message += output[len(output)-2]

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(email, password)
server.sendmail(email, send_to_email , message)
server.quit()