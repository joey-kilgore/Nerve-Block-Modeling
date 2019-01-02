: Original author: unknown
: Commented by D. Michael Ackermann on 06/30/2009
: Contact: dma18@case.edu
: Description: This mod file defines a point process for sinusoidal stimulation with ramped amplitude and freq



NEURON {
	POINT_PROCESS IClampMODSine		: Define point process for sinusoidal stim source 
	RANGE del, Tplat1, Tramp1, Tplat2, Tramp2, Tplat3, A1, A2, A3, f, i, offset	: Input parameters for process (defined in main body code)
	ELECTRODE_CURRENT i
}

UNITS { (nA) = (nanoamp) }	

PARAMETER {

	del (ms)				: stim delay (msec)
	Tplat1 (ms) <0, 1e9>			: duration of initial sinusoid stim (msec)
	Tramp1 (ms) <0, 1e9>			: duration of ramp1 of sinusoid stim (msec)
	Tplat2 (ms) <0, 1e9>			: duration of middle sinusoid stim (msec)
	Tramp2 (ms) <0, 1e9>			: duration of ramp2 of sinusoid stim (msec)
	Tplat3 (ms) <0, 1e9>			: duration of end sinusoid stim (msec)
	
	
	A1 (nA)				: starting stim amplitude (absolute, not peak-peak) (nA)
	A2 (nA)				: middle stim amplitude (absolute, not peak-peak) (nA)
	A3 (nA)				: end stim amplitude (absolute, not peak-peak) (nA)
	f (Hz)				: starting frequency of stimulation (Hz)
	
	offset (nA)				: DC offset (nA)
		
}

ASSIGNED { i (nA) }

INITIAL { i = 0 }

BREAKPOINT {
	at_time(del)							: breakpoint 
	at_time(del+Tplat1)
	at_time(del+Tplat1+Tramp1)
	at_time(del+Tplat1+Tramp1+Tplat2)
	at_time(del+Tplat1+Tramp1+Tplat2+Tramp2)
	at_time(del+Tplat1+Tramp1+Tplat2+Tramp2+Tplat3)

	if (t < del+Tplat1 && t > del) {
		i = (A1*sin(2*3.1415927*f*(t-del)*(0.001))) + offset	: define stim output waveform (/ by 1000 because
	} 
	else {
	
	if (t < del+Tplat1+Tramp1 && t > del+Tplat1) {
		i = ((A1+(A2-A1)*(t- Tplat1 - del)/(Tramp1))*sin(2*3.1415927*f*(t- Tplat1 - del)*(0.001))) + offset	: define stim output waveform (/ by 1000 because
	} 
	else {
	
	if (t < del+Tplat1+Tramp1+Tplat2 && t > del+Tplat1+Tramp1) {
		i = (A2*sin(2*3.1415927*f*(t - del - Tplat1 - Tramp1)*(0.001))) + offset	: define stim output waveform (/ by 1000 because
	} 
	
	else {
	
	if (t < del+Tplat1+Tramp1+Tplat2+Tramp2 && t > del+Tplat1+Tramp1+Tplat2) {
		i = ((A2+(A3-A2)*(t- del - Tplat1 - Tramp1 - Tplat2)/(Tramp2))*sin(2*3.1415927*f*(t- del - Tplat1 - Tramp1 - Tplat2)*(0.001))) + offset	: define stim output waveform (/ by 1000 because
	} 
	
	else {
	
	if (t < del+Tplat1+Tramp1+Tplat2+Tramp2+Tplat3 && t > del+Tplat1+Tramp1+Tplat2+Tramp2) {
		i = (A3*sin(2*3.1415927*f*(t - del - Tplat1 - Tramp1 - Tplat2 - Tramp2)*(0.001))) + offset	: define stim output waveform (/ by 1000 because
	} 
	
	else {							: of msec time scale for inputs		
		i = 0							: no current outside of stim duration
	}
	}
	}
	}
	}
}