 :Current Clamp

 NEURON {
 		 POINT_PROCESS Bi_trainIClamp
 		 RANGE del,train, high_amp,low_amp, freq, i, conv, pulsecount, onoff,cathod_dur,postcathod_dur,anod_dur, postanod_dur
 		 ELECTRODE_CURRENT i
 }

 UNITS { (na) = (nanoamp) }

 PARAMETER{
 		del (ms)
		cathod_dur(ms)
		postcathod_dur(ms)
		anod_dur(ms)
		postanod_dur(ms)
 		train (ms)
 		high_amp (na)
 		low_amp (na)
 		conv = 1000 (ms/s)
		freq (1/s)
 		pulsecount (s/s)
 		onoff (s/s)
		
		
 }

 ASSIGNED {
 		i (na)		
 }

 INITIAL  { LOCAL j,k
			
 			pulsecount = 0
 			onoff = 0
			freq = conv*(1/(cathod_dur+postcathod_dur+anod_dur + postanod_dur)) :1/period = frequency
           : k =  (train/conv)*freq  :is this right??
			k =  (train/conv)*freq       :Calculating the number of periods in the signal ( 1/freq = period (1/s) use conv to convert
						     : (1/s) to (1/ms)		
 			i = 0
			
			:use at_time to tell Neuron at what time all the discontinuities occur
 			FROM j = 0 TO k  {
 				at_time ((j*(conv/freq))+ del ) :first discontinuity
		 		at_time ((j*(conv/freq))+ del + cathod_dur ) :second
				at_time ((j*(conv/freq))+ del + cathod_dur+postcathod_dur ) :third
				at_time ((j*(conv/freq))+ del + cathod_dur+postcathod_dur+anod_dur) :fourth
 		  	}
 		  	at_time (del + train) :Just in case the period of signal doesn't divide evenly into the signal duration (aka train)
 }

 BREAKPOINT {

				freq =conv*(1/(cathod_dur+postcathod_dur+anod_dur + postanod_dur)) :1/period = frequency
 
		 		if (t < del + train && t > del){ :if you are not before signal starts of after it has ended
		 				if (t > del + (pulsecount*(conv/freq)) && t < del + (pulsecount*(conv/freq)) + cathod_dur)  {
						:if you are in duration of a high pulse signal
		 						
							i = high_amp
		 					onoff = 1

						}
						if(  t>=del + (pulsecount*(conv/freq)) + cathod_dur && t < del + (pulsecount*(conv/freq)) + cathod_dur+ postcathod_dur){
						:if you're inbetween high pulse and low pulse then i = 0
							i = 0
							onoff = 0
						}
						if(t >= del+(pulsecount*(conv/freq))+cathod_dur + postcathod_dur && t <del + (pulsecount*(conv/freq)) +cathod_dur+ postcathod_dur + anod_dur){
						:if your somewhere in duration of low pulse signal
							i = low_amp
							onoff = 1
	
						} 

						:if(t >= del + (pulsecount*(conv/freq)) + cathod_dur+ postcathod_dur + anod_dur && 
						:	t < del + (pulsecount*(conv/freq)) + cathod_dur+ postcathod_dur + anod_dur + postanod_dur ){
						:if you're inbetween low pulse and high puls of next period then i = 0
						:	i = 0
						:	onoff = 0

						:}

						if(t >=del + (pulsecount*(conv/freq)) + cathod_dur+ postcathod_dur + anod_dur){

		 					if (onoff == 0) {
		 						i = 0
		 					} 
							else {
		 						i = 0
		 						pulsecount = pulsecount + 1
		 						onoff = 0
		 					}
						}
		 		} 
				else {
		 				i = 0
		 				pulsecount = 0
		 				onoff = 0
		 		}
 }