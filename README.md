# Nerve Block Modeling

This code utilizes the NEURON program to create simulations of High Frequency Alternating Current (HFAC) blocking action potentials. The main models here are created from the MRG model. By creating simulations, millions of tests can be run one after another continously, allowing for testing of multiple different types of waveforms, on different fiber diameters, with different electrodes. Hopefully, this will allow us to get a better insight on the potential of HFAC nerve block.  
Please see the [WIKI](https://github.com/joey-kilgore/Nerve-Block-Modeling/wiki) for instructions on how to use this code base!  
Checkout YouTube Tutorial for this repository [Electrical-Nerve-Block-Modeling-Tutorial](https://www.youtube.com/playlist?list=PL-HiS65yepm4Jo8OU-ZKYyLbT7wxt7Kjr)

# Folder Structure
---
## Current Simulation  
This is where the current simulation can be found. By running NEURON and loading the models/nrnmech.dll and the CNOW_run.hoc file, the simulation begins. Note that the mod files need to be interpreted to C then compiled, this is done by running mknrndll on the models folder.  

---
## Data  
This is where data from simultions/experiments is put. All raw data is given usually in a csv format, then files are combined into a large excel sheet that can also be found here.  

---
## Deprecated Code  
This is where past code goes after being replaced, or simply just bloatware from the main simulation. The authors of this code have contributed to this codebase, and their code can be used as an excellent (or terrible) example.  

---
## Python Scripts  
Because NEURON can not run multiple simulations at the same time, Python scripts can be used to have multiple simulations running concurrently. There are also some other scripts for getting updates remotely.  

---
## R Code  
The code here is meant to be used as reference of premade code snippets for analyzing the large csv files that can be generated from these simulations.  

---
## Wiki
This stores the images for the wiki pages. It is HIGHLY recommended that you check out the [wiki pages](https://github.com/joey-kilgore/Nerve-Block-Modeling/wiki) to get a better understanding of the NEURON code base. 

---
# Related Works  
The MRG model is main model being used in this repository and was originally described in  
C. C. McIntyre, A. G. Richardson, and W. M. Grill, “Modeling the ex- citability of mammalian nerve fibers: Influence of afterpotentials on the recovery cycle,” J. Neurophysiol., vol. 87, pp. 995–1006, 2002.  

The additional frequency-dependent membrane capacitance was described in  
Howell B, Medina L E and Grill W M 2015 Effects of frequency-dependent membrane capacitance on neural excitability J. Neural Eng. 12 056015  
*Special thanks to Dr. Grill and Dr. Medina for providing additional code and support.*  

The sensory axon model is described in  
Gaines, J. L., Finn, K. E., Slopsema, J. P., Heyboer, L. A., &amp; Polasek, K. H. (2018). A model of motor and sensory axon activation in the median nerve using surface electrical stimulation. Journal of Computational Neuroscience, 45(1), 29-43. doi:10.1007/s10827-018-0689-5  
*Special thanks to Dr. Polasek for providing additional code and support.*  

Previous works that have utilized this code base or contributed in some form or another  
 - Ackermann, D. M., Bhadra, N., Gerges, M., &amp; Thomas, P. J. (2011). Dynamics and sensitivity analysis of high-frequency conduction block. Journal of Neural Engineering, 8(6), 065007. doi:10.1088/1741-2560/8/6/065007  
 - Ackermann, D., Foldes, E., Bhadra, N., &amp; Kilgore, K. (2009). Effect of Bipolar Cuff Electrode Design on Block Thresholds in High-Frequency Electrical Neural Conduction Block. IEEE Transactions on Neural Systems and Rehabilitation Engineering, 17(5), 469-477. doi:10.1109/tnsre.2009.2034069  
 - Bhadra, N., &amp; Kilgore, K. (2004). Direct Current Electrical Conduction Block of Peripheral Nerve. IEEE Transactions on Neural Systems and Rehabilitation Engineering, 12(3), 313-324. doi:10.1109/tnsre.2004.834205  
 - Bhadra, N., Lahowetz, E. A., Foldes, S. T., &amp; Kilgore, K. L. (2007). Simulation of high-frequency sinusoidal electrical block of mammalian myelinated axons. Journal of Computational Neuroscience, 22(3), 313-326. doi:10.1007/s10827-006-0015-5  
 - Eggers, T. E., Kilgore, J. A., Green, D., Vrabec, T., Kilgore, K. L., &amp; Bhadra, N. (2021). Combining direct current and kilohertz frequency alternating current to mitigate onset activity during electrical nerve block. Journal of Neural Engineering. doi:10.1088/1741-2552/abebed  
 - K. L. Kilgore and N. Bhadra, "High Frequency Mammalian Nerve Conduction Block: Simulations and Experiments," 2006 International Conference of the IEEE Engineering in Medicine and Biology Society, New York, NY, 2006, pp. 4971-4974, doi: 10.1109/IEMBS.2006.259254.  
 - Miles, J. D., Kilgore, K. L., Bhadra, N., &amp; Lahowetz, E. A. (2007). Effects of ramped amplitude waveforms on the onset response of high-frequency mammalian nerve block. Journal of Neural Engineering, 4(4), 390-398. doi:10.1088/1741-2560/4/4/005  
(Among others that will be added...)
