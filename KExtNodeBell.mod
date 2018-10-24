: Jaymin Patel
: Created 10/06/09
: Filename = KExtNodeBell.mod
: Version = 1.0
: Desc = Mod file for implementing EC K+ accumulation in MRG model in the extranodal space combined with the model from Bellinger et al
: Modified from code by Hines, M.L. and Carnevale, N.T. Expanding NEURON's repertoire of mechanisms with NMODL. Neural Computation 12:995-1007, 2000.



NEURON {
	SUFFIX KExtNodeBell      :Suffix tells Neuron that this is a Density Mechanism, with Suffix KExtNode
	USEION k READ ik WRITE ko   :This mod file uses the K ion, reads the sum of all ik in the segment and writes ko ([K]ec) based on this ik and a diffusion mechanism)
	GLOBAL kbath   :"bath" concentration of potassium
	RANGE Dk, sp
}

UNITS {    :Unit declaration/definition
	(mV)    = (millivolt)
	(mA)    = (milliamp)
	FARADAY = (faraday) (coulombs)
	(molar) = (1/liter)
	(mM)    = (millimolar)
	PI = (pi) (1)
	(um) = (micron)
}

PARAMETER {    :Parameters = constants
	ko0     =  4.30794 (mM)  : initial external concentration
	Dk = 1.85 (um2/ms)
	nodalGap = 1.9 (um)
	rn = 0.95 (um)
	extracellularVolumePerLength (um2)
	crossSectionalArea (um2)
	kbathVolumePerLength = 1e15 (um2)
	radialCrosssectionalAreaPerLength (um)
	radialRateConstant (um2/ms)
	kbath = 4.30794 (mM)
}
ASSIGNED { ik  (mA/cm2) }   :Assigned statements are algebraic statements. h

STATE { 
	ko  (mM) :ko is a state variable, i.e. one that is updated from solving a DE (below)
}    

INITIAL {
	ko = ko0
	extracellularVolumePerLength =PI * ( (rn+nodalGap)^2 - rn^2 )
	crossSectionalArea = extracellularVolumePerLength

	radialCrosssectionalAreaPerLength = 2 * PI * ( rn + nodalGap )
	radialRateConstant = Dk * radialCrosssectionalAreaPerLength / nodalGap
}

BREAKPOINT { SOLVE conc METHOD sparse }

KINETIC conc {
	COMPARTMENT crossSectionalArea { ko }
	COMPARTMENT kbathVolumePerLength { kbath }
	LONGITUDINAL_DIFFUSION Dk*extracellularVolumePerLength { ko }
	~ ko << (ik/(FARADAY)*2*PI*rn*(1e4))  : (1e4 in Bellinger model) //changed back to 1e4 from 1e6 TE 03/16/18
	~ ko <-> kbath (radialRateConstant,radialRateConstant)
}  