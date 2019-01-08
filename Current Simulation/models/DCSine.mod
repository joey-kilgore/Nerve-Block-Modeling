:Current Clamp
: Meant to act as both a DC, and Sine wave as needed

NEURON{
    POINT_PROCESS IDCSineClamp 
    RANGE dcdel, dcdur, dcamp, sinedel, sinedur, sineamp, sinef
    ELECTRODE_CURRENT i
}

UNITS { (nA) = (nanoamp)}

PARAMETER {
    dcdel (ms)  : delay for DC current
    dcdur (ms)  : duration for DC current
    dcamp (nA)  : amplitude for DC current

    sinedel (ms)    : delay for sinusoid
    sinedur (ms)    : duration for sinusoid
    sineamp (nA)    : amplitude for sinusoid (absolute not peak to peak)
    sinef (Hz)      : frequency for sinusoid 
}

ASSIGNED { i (nA) }

INITIAL { i = 0 }

BREAKPOINT {
    at_time(dcdel)              : points of discontinuity occur when the
    at_time(dcdel + dcdur)      :   DC or Sine wave start (del) and stop (del+dur)
    at_time(sinedel)
    at_time(sinedel + sinedur)

    if(t>dcdel && t<(dcdel+dcdur)){
        i = dcamp
    } else {    
        i = 0
    }

    if(t>sinedel && t<(sinedel+sinedur)){
        i = (sineamp*sin(2*3.1415927*sinef*(t-sinedel)*(0.001))) + i  : define sine output waveform
    }
}