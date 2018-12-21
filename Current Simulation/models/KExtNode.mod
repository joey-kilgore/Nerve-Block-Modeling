: D. Michael Ackermann
: Created 6/23/08
: Filename = KExtNode.mod
: Version = 1.0
: Desc = Mod file for implementing EC K+ accumulation in MRG model in the extranodal space
: Modified from code by Hines, M.L. and Carnevale, N.T. Expanding NEURON's repertoire of mechanisms with NMODL. Neural Computation 12:995-1007, 2000.



NEURON {
  SUFFIX KExtNode      :Suffix tells Neuron that this is a Density Mechanism, with Suffix KExtNode
  USEION k READ ik WRITE ko   :This mod file uses the K ion, reads the sum of all ik in the segment and writes ko ([K]ec) based on this ik and a diffusion mechanism)
  GLOBAL kbath   :"bath" concentration of potassium
  RANGE fhspace, txfer      :declare range variables (i.e. could vary with position), fhspace & txfer
}

UNITS {    :Unit declaration/definition
  (mV)    = (millivolt)
  (mA)    = (milliamp)
  FARADAY = (faraday) (coulombs)
  (molar) = (1/liter)
  (mM)    = (millimolar)
}

PARAMETER {    :Parameters = constants
  kbath   =  1.85 (mM)        : external bath concentration (set to 2.9 mM to match ko initial of fhspace)
  fhspace = 30000 (angstrom)  : effective thickness of F-H space (30,000 A = 3um)
  txfer   =  5 (ms)  : tau for F-H space <-> bath exchange = 30-100
}
ASSIGNED { ik  (mA/cm2) }   :Assigned statements are algebraic statements. h

STATE { ko  (mM) }    :ko is a state variable, i.e. one that is updated from solving a DE (below)

BREAKPOINT { SOLVE state METHOD cnexp }   :Breakpoint commands are executed at the beginning of each model step iteration (before Neuron ODEs are iterated), solved using Crank-Nicholson method

DERIVATIVE state {
  ko' = (1e8)*ik/(fhspace*FARADAY) + (kbath - ko)/txfer   :The DE for [K]ec -- term 1 = due to K+ currents, term 2 = diffusion of K+ into bath
}