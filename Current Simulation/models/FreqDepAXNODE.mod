TITLE Motor Axon Node channels with frequency dependent capacitance

: Base of this code is the AXNODE.mod, see that for reference
: Understanding the frequency dependent capacitance
: based on "Effects of Frequency-Dependent Membrane Capacitance on
: 	Neural Excitability" (Howell B, Medina L E, Grill W M, 2016)

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	SUFFIX freqdepaxnode
	NONSPECIFIC_CURRENT ina
	NONSPECIFIC_CURRENT inap
	NONSPECIFIC_CURRENT ik
	NONSPECIFIC_CURRENT il
	NONSPECIFIC_CURRENT icf
	RANGE gnapbar, gnabar, gkbar, gl, ena, ek, el
	RANGE mp_inf, m_inf, h_inf, s_inf
	RANGE tau_mp, tau_m, tau_h, tau_s
	RANGE cdelta, ctau
}


UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER {

	gnapbar = 0.01	(mho/cm2)	: Maximum persistent Na conductance
	gnabar	= 3.0	(mho/cm2)	: Maximum fast Na conductance
	gkbar   = 0.08 	(mho/cm2)	: Maximum slow K conductance
	gl	= 0.007 (mho/cm2)	: Nodal leadage conductance
	ena     = 50.0  (mV)	: Na Nernst potential
	ek      = -90.0 (mV)	: K Nernst potential
	el	= -90.0 (mV)	: Leakage reversal potential
	celsius		(degC)
	dt              (ms)
	v               (mV)
	vtraub=-80	
	ampA = 0.01
	ampB = 27
	ampC = 10.2
	bmpA = 0.00025
	bmpB = 34
	bmpC = 10
	amA = 1.86
	amB = 21.4
	amC = 10.3
	bmA = 0.086
	bmB = 25.7
	bmC = 9.16
	ahA = 0.062
	ahB = 114.0
	ahC = 11.0
	bhA = 2.3
	bhB = 31.8
	bhC = 13.4
	asA = 0.3
	asB = -27
	asC = -5
	bsA = 0.03
	bsB = 10
	bsC = -1
	cdelta = .9
	ctau = .00001591549
}

STATE {
	mp m h s vcd
}

ASSIGNED {
	inap    (mA/cm2)
	ina	(mA/cm2)
	ik      (mA/cm2)
	il      (mA/cm2)
	icf		(mA/cm2)
	mp_inf
	m_inf
	h_inf
	s_inf
	tau_mp
	tau_m
	tau_h
	tau_s
	q10_1
	q10_2
	q10_3
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	inap = gnapbar * mp*mp*mp * (v - ena)
	ina = gnabar * m*m*m*h * (v - ena)
	ik   = gkbar * s * (v - ek)
	il   = gl * (v - el)
	icf = (v - vcd)*cdelta / ctau
}

DERIVATIVE states {   
	: exact Hodgkin-Huxley equations
    evaluate_fct(v)
	mp'= (mp_inf - mp) / tau_mp
	m' = (m_inf - m) / tau_m
	h' = (h_inf - h) / tau_h
	s' = (s_inf - s) / tau_s
	vcd' = 1/ctau * (v - vcd)
}

UNITSOFF

INITIAL {
:	Q10 adjustment
	q10_1 = 2.2 ^ ((celsius-20)/ 10 )
	q10_2 = 2.9 ^ ((celsius-20)/ 10 )
	q10_3 = 3.0 ^ ((celsius-36)/ 10 )

	evaluate_fct(v)
	mp = mp_inf
	m = m_inf
	h = h_inf
	s = s_inf
}

PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b,v2
	: persistant sodium (mp)
	a = q10_1*vtrap1(v)
	b = q10_1*vtrap2(v)
	tau_mp = 1 / (a + b)
	mp_inf = a / (a + b)

	: fast sodium (m)
	a = q10_1*vtrap6(v)
	b = q10_1*vtrap7(v)
	tau_m = 1 / (a + b)
	m_inf = a / (a + b)

	: fast sodium (h)
	a = q10_2*vtrap8(v)
	b = q10_2*bhA / (1 + Exp(-(v+bhB)/bhC))
	tau_h = 1 / (a + b)
	h_inf = a / (a + b)

	v2 = v - vtraub : convert to traub convention

	: slow potassium (s)
	a = q10_3*asA / (Exp((v2+asB)/asC) + 1) 
	b = q10_3*bsA / (Exp((v2+bsB)/bsC) + 1)
	tau_s = 1 / (a + b)
	s_inf = a / (a + b)
}

FUNCTION vtrap(x) {
	if (x < -50) {
		vtrap = 0
	}else{
		vtrap = bsA / (Exp((x+bsB)/bsC) + 1)
	}
}

FUNCTION vtrap1(x) { : alpha equation for mp
	if (fabs((x+ampB)/ampC) < 1e-6) {
		vtrap1 = ampA*ampC
	}else{
		vtrap1 = (ampA*(x+ampB)) / (1 - Exp(-(x+ampB)/ampC))
	}
}

FUNCTION vtrap2(x) { : beta equation for mp
	if (fabs((x+bmpB)/bmpC) < 1e-6) {
		vtrap2 = bmpA*bmpC : Ted Carnevale minus sign bug fix
	}else{
		vtrap2 = (bmpA*(-(x+bmpB))) / (1 - Exp((x+bmpB)/bmpC))
	}
}

FUNCTION vtrap6(x) { : alpha equation for m
	if (fabs((x+amB)/amC) < 1e-6) {
		vtrap6 = amA*amC
	}else{
		vtrap6 = (amA*(x+amB)) / (1 - Exp(-(x+amB)/amC))
	}
}

FUNCTION vtrap7(x) { : beta equation for m
	if (fabs((x+bmB)/bmC) < 1e-6) {
		vtrap7 = bmA*bmC : Ted Carnevale minus sign bug fix
	}else{
		vtrap7 = (bmA*(-(x+bmB))) / (1 - Exp((x+bmB)/bmC))
	}
}

FUNCTION vtrap8(x) { : alpha equation for h
	if (fabs((x+ahB)/ahC) < 1e-6) {
		vtrap8 = ahA*ahC : Ted Carnevale minus sign bug fix
	}else{
		vtrap8 = (ahA*(-(x+ahB))) / (1 - Exp((x+ahB)/ahC)) 
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