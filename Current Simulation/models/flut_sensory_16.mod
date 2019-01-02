TITLE Motor Axon Node channels

: 06/16
: Jessica Gaines
:
: Modification of channel properties
:
: 04/15
: Lane Heyboer
:
: Fast K+ current
: Ih current
:
: 02/02
: Cameron C. McIntyre
:
: Fast Na+, Persistant Na+, Slow K+, and Leakage currents 
: responsible for nodal action potential
: Iterative equations H-H notation rest = -80 mV
:
: This model is described in detail in:
:
: McIntyre CC, Richardson AG, and Grill WM. Modeling the excitability of
: mammalian nerve fibers: influence of afterpotentials on the recovery
: cycle. Journal of Neurophysiology 87:995-1006, 2002.

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	SUFFIX flut_sensory_16
	NONSPECIFIC_CURRENT ik
	NONSPECIFIC_CURRENT il
	NONSPECIFIC_CURRENT iq
	NONSPECIFIC_CURRENT ikf
	RANGE gkbar, gl, gq, gkf, ek, el, eq, ekf
	RANGE s_inf, q_inf, n_inf
	RANGE tau_s, tau_q, tau_n
}


UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER {

    : channel conductances
	gkbar   = 0.001324 (mho/cm2)
	gl	= 0.0001716 (mho/cm2)
	gq	= 0.003102 (mho/cm2)
	gkf	= 0.02737 (mho/cm2)

    : reversal potentials
	ek      = -90.0 (mV)
	el	= -90.0 (mV)
	eq	= -54.9 (mV)
	ekf	= -90.0 (mV)

    : read in from .hoc file
	celsius		(degC)
	dt              (ms)
	v               (mV)
	vtraub=-80

    : parameters determining rate constants

    : slow K+
	asA = 0.3
	asB = -27
	asC = -5
	bsA = 0.03
	bsB = 10
	bsC = -1

    : HCN
	aqA = .00522
	aqB = -94.2
	aqC = -12.2
	bqA = .00522
	bqB = -94.2
	bqC = -12.2

    : fast K+
	anA = 0.0462
	anB = -83.2
	anC = 1.1
	bnA = 0.0824
	bnB = -66
	bnC = 10.5
}

STATE {
	s q n
}

ASSIGNED {
	ik      (mA/cm2)
	il      (mA/cm2)
	iq	(mA/cm2)
	ikf	(mA/cm2)
	s_inf
	q_inf
	n_inf
	tau_s
	tau_q
	tau_n
	q10_1
	q10_2
	q10_3
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ik   = gkbar * s * (v - ek)
	il   = gl * (v - el)
	iq = gq * q * (v-eq)
	ikf = gkf * n*n*n*n* (v-ekf)
}

DERIVATIVE states {   : exact Hodgkin-Huxley equations
       evaluate_fct(v)
	s' = (s_inf - s) / tau_s
	q' = (q_inf - q) / tau_q
	n' = (n_inf - n) / tau_n
}

UNITSOFF

INITIAL {
:
:	Q10 adjustment
:   Temperature dependence
:

	q10_1 = 2.2 ^ ((celsius-20)/ 10 )
	q10_2 = 2.9 ^ ((celsius-20)/ 10 )
	q10_3 = 3.0 ^ ((celsius-36)/ 10 )

	evaluate_fct(v)
	s = s_inf
	q = q_inf
	n = n_inf
}

PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b,v2

	v2 = v - vtraub : convert to traub convention

    : slow K+
	a = q10_3*asA / (Exp((v2+asB)/asC) + 1) 
	b = q10_3*bsA / (Exp((v2+bsB)/bsC) + 1)
	tau_s = 1 / (a + b)
	s_inf = a / (a + b)

    : HCN
	a = q10_3*aqA * (Exp((v-aqB)/aqC)) 
	b = q10_3*bqA / (Exp((v-bqB)/bqC))
	tau_q = 1 / (a + b)
	q_inf = a / (a + b)

    : fast K+
	a = q10_3*vtrapNA(v) 
	b = q10_3*vtrapNB(v)
	tau_n = 1 / (a + b)
	n_inf = a / (a + b)
}

: vtrap functions to prevent discontinuity
FUNCTION vtrapNA(x){
    if(fabs((anB - x)/anC) < 1e-6){
        vtrapNA = anA*anC
    }else{
        vtrapNA = anA*(v-anB)/(1-Exp((anB-v)/anC))
    }
}

FUNCTION vtrapNB(x){
    if(fabs((x - bnB)/bnC) < 1e-6){
        vtrapNB = bnA*bnC  
    }else{
        vtrapNB = bnA*(bnB-v)/(1-Exp((v-bnB)/bnC))
    }
}

FUNCTION Exp(x) {
	if (x < -100) {
		Exp = 0
	}else{
		Exp = exp(x)
	}
}

UNITSON