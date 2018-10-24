: Jaymin Patel
: Created 10/06/09
: Filename = NaIntNode.mod
: Version = 1.0
: Desc = Mod file for implementing EC K+ accumulation in MRG model in the extranodal space
: Modified from code by Hines, M.L. and Carnevale, N.T. Expanding NEURON's repertoire of mechanisms with NMODL. Neural Computation 12:995-1007, 2000.



NEURON {
  SUFFIX NaIntNode      :Suffix tells Neuron that this is a Density Mechanism, with Suffix NaIntNode
  USEION na READ ina WRITE nai   :This mod file uses the Na+ ion, reads the sum of all ina in the segment and writes nai ([Na]ic) based on this ina and a diffusion mechanism)
  RANGE N2PN2JP_vol, N_SA
}

UNITS {    :Unit declaration/definition
  (mV)    = (millivolt)
  (mA)    = (milliamp)
  FARADAY = (faraday) (coulombs)
  (molar) = (1/liter)
  (mM)    = (millimolar)
  (um)	  = (micron)
}

PARAMETER {    :Parameters = constants
  N2PN2JP_vol = 28.39 (um3) : volume in microns cubed of the node and two adjoining paranodal and juxtaparanodal regions
  N_SA = 1.7931 (um2) : surface area of node
  nai0     =  19.24562 (mM)  : initial internal concentration
}
ASSIGNED { ina  (mA/cm2) }   :Assigned statements are algebraic statements. h

STATE { 
  nai (mM) :nai is a state variable, i.e. one that is updated from solving a DE (below)
}    

INITIAL {
  nai = nai0
}

BREAKPOINT { SOLVE state METHOD cnexp }   :Breakpoint commands are executed at the beginning of each model step iteration (before Neuron ODEs are iterated), solved using Crank-Nicholson method

DERIVATIVE state {
   nai' = -(1e4)*(ina*N_SA)/(FARADAY*N2PN2JP_vol)
}   