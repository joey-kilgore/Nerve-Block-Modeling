 :Current Clamp

 NEURON {
	POINT_PROCESS IClampTri
	RANGE del,dur, amp, freq, i, conv, pulsecount, offset
	ELECTRODE_CURRENT i
 }

 UNITS { (na) = (nanoamp) }

 PARAMETER{
	del (ms)
	dur (ms)
	amp (na)
	conv = 1000 (ms/s)
	freq (1/s)
	pulsecount (s/s)
	offset (na)	
 }

 ASSIGNED {
	i (na)		
 }

 INITIAL  { LOCAL per,j,k
	pulsecount = 0
	per = conv/freq 
	k =  dur/per       :Calculating the number of periods in the signal ( 1/freq = period (1/s) use conv to convert
						: (1/s) to (1/ms)		
	i = 0
	offset = 0
	
	:use at_time to tell Neuron at what time all the discontinuities occur
	FROM j = 0 TO k  {
		at_time ((j*per+del)) :first discontinuity
		at_time ((j*per)+ del + per*.25 ) :second
		at_time ((j*per)+ del + per*.75) :third
	}
	at_time (del + dur) :Just in case the period of signal doesn't divide evenly into the signal duration
 }

 BREAKPOINT { LOCAL per
	per = conv/freq         
                
	if (t < del + dur && t > del){ :if you are not before signal starts of after it has ended
		if (t > del + (pulsecount*(per)) && t < del + ((pulsecount+.25)*(per)))  {
		:if you are in 0-pi/2 in the phase	
			i = offset+(t-(pulsecount*per)-del)*4*amp/per
		}
		if(t>=del + ((pulsecount+.25)*(per))&& t < del + ((pulsecount+.75)*(per))){
		:between pi/2 and 3pi/2 in phase
			i = offset+amp+(t-((pulsecount+.25)*per)-del)*-4*amp/per
			
		}
		if(t >= del+(pulsecount*(per))+per*.75 && t <del + ((pulsecount+1)*per)){
		:between 3pi/2 and 2pi
			i = -1*amp+offset+(t-((pulsecount+.75)*per)-del)*4*amp/per         	
		}
		if (t>=((pulsecount+1)*per+del)){
			pulsecount = pulsecount+1
		}
	} 
	else {
		i = 0
		pulsecount = 0
	}
 }

