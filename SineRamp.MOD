: Original author: Vrabec
: Commented by D. Michael Ackermann on 06/30/2009
: Contact: dma18@case.edu
: Description: This mod file defines a point process for a ramped sinusoidal stimulation segment



NEURON {
	POINT_PROCESS SineRamp		: Define point process for sinusoidal stim source 
	RANGE DCAmp_vec   : DC offset parameters
	RANGE HFAC_vec	     : HFAC paramters
	RANGE freq_vec	     : frequency paramters
	RANGE Ramptime_vec
	RANGE f 
	RANGE segment, num_of_pts
	RANGE i, DCAmp, HFACAmp, freq, TimeStart, dDC, dHFAC, dfreq, virtualt, oldt, oldfreq
	RANGE virtualfreq
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
	DCAmp_vec[12] (nA)
	HFAC_vec[12] (nA)
	freq_vec[12] (nA)
	Ramptime_vec[12] (ms)
	segment
	newendtime (ms)
	num_of_pts
	TimeStop (ms)
	virtualfreq (Hz)
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
	virtualfreq = 0

}

BREAKPOINT {
	virtualfreq = dfreq
	
	if ( (t < TimeStop)){	: update DC and HFAC values for this segment

		i = (HFACAmp*sin(2*PI*freq*(virtualt)/1000)) + DCAmp

		oldfreq = freq

		dDC = (DCAmp_vec[segment+1]-DCAmp_vec[segment])/Ramptime_vec[segment+1]*(dt/2)
		dHFAC = (HFAC_vec[segment+1]-HFAC_vec[segment])/Ramptime_vec[segment+1]*(dt/2)
		dfreq = (freq_vec[segment+1]-freq_vec[segment])/(Ramptime_vec[segment+1])*(dt/2)
	
		DCAmp = dDC+DCAmp
		HFACAmp = dHFAC+HFACAmp
		freq = dfreq +freq

		if (freq !=0) {
			oldt = (oldfreq*virtualt)/freq
			virtualt = oldt+dt/2
		}

	} else if (segment<num_of_pts) {	:  move onto next segment

		DCAmp = DCAmp_vec[segment+1]

		segment = segment +1
		TimeStop = TimeStop + Ramptime_vec[segment+1]	

	}
	else {		: at the last segment, hold the values

		DCAmp = DCAmp_vec[segment+1]


		i = (HFACAmp*sin(2*PI*freq*(virtualt)/1000)) + DCAmp
		virtualt = virtualt + dt/2
		
	}


}