# Nerve Block Modeling

This code utilizes the NEURON program to create simulations of High Frequency Alternating Current (HFAC) to block action potentials. The main models here are created from the MRG model. By creating simulations, millions of tests can be ran one after another continously, allowing for testing of multiple different types of waveforms, on different fiber diameters, with different electrodes. Hopefully, this will allow us to get a better insight on the potential of HFAC on nerve block.  

---
## Main Simulation  
This is where the current simulation can be found. By running NEURON and loading the models/nrnmech.dll and the CNOW_run.hoc file, the simulation begins. Note that the mod files need to be interpreted to C then compiled, this is done by running mknrndll on the models folder.  

---
## Data  
This is where data from simultions/experiments is put. All raw data is given usually in a csv format, then files are combined into a large excel sheet that can also be found here.  

---
## Deprecated Code  
This is where past code goes after being replaced, or simply just bloat to the main simulation. The authors of this code have contributed to this codebase, and there code can be used as an excellent (or terrible) example.  

---
## Python Scripts  
Because NEURON can not run multiple simulations at the same time, Python scripts can be used to have multiple simulations running concurrently. There are also some other scripts for getting updates remotely.  

---
## R Code  
The code here is meant to be used as reference of premade code snippets for analyzing the large csv files that can be generated from these simulations.  

---
## Wiki
This stores the images for the wiki pages. It is HIGHLY recommended that you check out the [wiki pages](https://github.com/mrjoeboo123/NEURON/wiki) to get a better understanding of the NEURON code base. 

