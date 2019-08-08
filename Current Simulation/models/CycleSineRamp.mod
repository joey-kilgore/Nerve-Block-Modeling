: Original author: Vrabec
: Commented by D. Michael Ackermann on 06/30/2009
: Contact: dma18@case.edu
: Description: This mod file defines a point process for a ramped sinusoidal stimulation segment



NEURON {
	POINT_PROCESS CycleSineRamp		: Define point process for sinusoidal stim source 
	RANGE DCAmp_vec   : DC offset parameters
	RANGE HFAC_vec	     : HFAC paramters
	RANGE freq_vec	     : frequency paramters
	RANGE Ramptime_vec
	RANGE f 
	RANGE segment, num_of_pts
	RANGE i, DCAmp, HFACAmp, freq, TimeStart, dDC, dHFAC, dfreq, virtualt, oldt, oldfreq
	RANGE freqsample
	RANGE cycletime
	RANGE TimeStop
	ELECTRODE_CURRENT i
}

UNITS {
  (nA) = (nanoamp)
  PI = (pi) (1)
}

PARAMETER {

	f (Hz)				: starting frequency of stimulation (Hz)

}

ASSIGNED { 

	i (nA) 
	TimeStart (ms)
	DCAmp (nA)
	HFACAmp (nA)
	freq (Hz) 
	dDC (nA)
	dHFAC (nA)
	dfreq (Hz)
	virtualt (sec)
	oldt (ms)
	oldfreq (Hz)
	DCAmp_vec[6] (nA)
	HFAC_vec[6] (nA)
	freq_vec[6] (nA)
	Ramptime_vec[6] (ms)
	segment
	newendtime (ms)
	num_of_pts
	TimeStop (ms)
	cycletime (ms)
	freqsample (Hz)
}

INITIAL { 
	i = 0 
	TimeStart = 0
	oldt = 0
	oldfreq = 500

	DCAmp_vec[0] = 0
	HFAC_vec[0] = 0
	freq_vec[0] = 0
	segment = 0

	TimeStop = Ramptime_vec[1]	: initial stop time is the time of the first Ramptime vector

	if (TimeStop > 0) {

		DCAmp = 0
		HFACAmp = 0
		freq = 0

	} else {

		DCAmp = DCAmp_vec[1]
		HFACAmp = HFAC_vec[1]
		freq = freq_vec[1]
	}

	
	dDC = 0
	dHFAC = 0
	dfreq = 0

	virtualt = 0

	cycletime = 0
	freqsample = 0

}

BREAKPOINT {

	
	if (t < TimeStop){	: update DC and HFAC values for this segment

		i = (HFACAmp*sin(2*PI*freq_vec[segment+1]*(virtualt)/1000)) + DCAmp

		oldfreq = freq

		dDC = (DCAmp_vec[segment+1]-DCAmp_vec[segment])/Ramptime_vec[segment+1]*(dt/2)
		dHFAC = (HFAC_vec[segment+1]-HFAC_vec[segment])/Ramptime_vec[segment+1]*(dt/2)
		dfreq = (freq_vec[segment+1]-freq_vec[segment])/(Ramptime_vec[segment+1])*(dt/2)
	
		DCAmp = dDC+DCAmp
		HFACAmp = dHFAC+HFACAmp
		freq = dfreq +freq

		if (freq !=0) {

			if (cycletime == 0){  : if at the start of a cyle

				freqsample = freq			: get new freqsample
			}

			if (cycletime<2*(1000/freq_vec[segment+1])){  : cycletime is within one sine cycle
	
				virtualt = virtualt+dt/2	: regular sine
			}
			else{
			
				virtualt = 0		: goes to zero in between cycles.
				freqsample = freq		: get new freqsample
			
			}

			if (cycletime>(1000/freqsample)){	: cycletime is at the end of a sampled cycle

				cycletime = 0			: reset cycletime
			}
			else{
			
				cycletime = cycletime+dt
			}
		}

	} else if (segment<num_of_pts) {	:  move onto next segment
		segment = segment +1
		TimeStop = TimeStop + Ramptime_vec[segment+1]	

	}
	else {		: at the last segment, hold the values

		i = (HFACAmp*sin(2*PI*freq*(virtualt)/1000)) + DCAmp
		virtualt = virtualt + dt/2
		
	}


}