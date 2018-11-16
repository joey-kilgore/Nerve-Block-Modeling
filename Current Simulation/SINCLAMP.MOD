: Original author: unknown
: Commented by D. Michael Ackermann on 11/29/2007
: Contact: dma18@case.edu
: Description: This mod file defines a point process for sinusoidal stimulation given standard input parameters.



NEURON {
	POINT_PROCESS IClampSine		: Define point process for sinusoidal stim source 
	RANGE del, dur, amp, i, f, offset	: Input parameters for process (defined in main body code)
	ELECTRODE_CURRENT i
}

UNITS { (nA) = (nanoamp) }	

PARAMETER {
	del (ms)				: stim delay (msec)
	dur (ms) <0, 1e9>			: duration of stim (msec)
	amp (nA)				: stim amplitude (absolute, not peak-peak) (nA)
	f (Hz)				: frequency of stimulation (Hz)
	offset (nA)				: DC offset (nA)
}

ASSIGNED { i (nA) }

INITIAL { i = 0 }

BREAKPOINT {
	at_time(del)							: breakpoint 
	at_time(del+dur)
	if (t < del + dur && t > del) {
		i = (amp*sin(2*3.1415927*f*(t-del)*(0.001))) + offset	: define stim output waveform (/ by 1000 because
	} else {							: of msec time scale for inputs		
		i = 0							: no current outside of stim duration
	}
}