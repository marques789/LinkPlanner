# include "netxpto.h"
# include "local_oscillator.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======
>>>>>>> Romil
# include <algorithm>
# include <complex>
# include <iostream>
# include <fstream>
# include <random>

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======
>>>>>>> Romil
using namespace std;


void LocalOscillator::initialize(void){
<<<<<<< HEAD
<<<<<<< HEAD

	outputSignals[0]->setSamplingPeriod(samplingPeriod);
=======
	
	outputSignals[0]->setSamplingPeriod(samplingPeriod);
<<<<<<< HEAD
>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======

	outputSignals[0]->setSamplingPeriod(samplingPeriod);
>>>>>>> Romil
	outputSignals[0]->setSymbolPeriod(symbolPeriod);

	outputSignals[0]->centralWavelength= outputOpticalWavelength;
	outputSignals[0]->centralFrequency = outputOpticalFrequency;
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
	outputSignals[0]->setCentralWavelength(wavelength);
	outputSignals[0]->setCentralFrequency(frequency);
>>>>>>> AnaLuisa
>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======
>>>>>>> Romil

}


bool LocalOscillator::runBlock(void){

<<<<<<< HEAD
<<<<<<< HEAD
=======

    normal_distribution<double> distribution(0, 1);

	t_real dt = samplingPeriod;
	t_real wvlgth = wavelength;
	t_real noisesignal;
	t_real noiselo;

>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======
>>>>>>> Romil
	int process = outputSignals[0]->space();
	
	if (process == 0) return false;

<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======
>>>>>>> Romil
	//t_complex outAverage(cos(phase), sin(phase));
	t_complex out(cos(phase), sin(phase));
	double outOpticalPower=opticalPower;
	double wavelength = outputSignals[0]->getCentralWavelength();
	double deltaPhase = sqrt(PLANCK_CONSTANT*SPEED_OF_LIGHT / (2 * opticalPower*samplingPeriod*wavelength));
	double dt = outputSignals[0]->getSamplingPeriod();


	normal_distribution<double> distribution(0, 1);
	
	double noiseRIN;
	
	out= .5*sqrt(opticalPower)*out;

	for (int i = 0; i < process; i++) {
		if (signaltoNoiseRatio != 0)
		{
			t_real noise = distribution(generatorRIN);
			outOpticalPower = opticalPower + opticalPower/signaltoNoiseRatio*noise;
			out = .5*sqrt(outOpticalPower)*out;
		}
		outputSignals[0]->bufferPut((t_complex)out);
	}
<<<<<<< HEAD
<<<<<<< HEAD

=======
=======
	t_real real = cos(phase);
	t_real imag = sin(phase);
	t_complex lo(real, imag);
	t_real powerlo = opticalPower;

	t_complex out = lo;

	for (int i = 0; i < process; i++) {


		noisesignal = distribution(generator1);
		noiselo = distribution(generator2);

		t_complex loout;

        if (shotNoise) {
            t_real powerlooutsqrted = sqrt(powerlo) + sqrt(PLANCK_CONSTANT*SPEED_OF_LIGHT / (dt * wvlgth))*noiselo*1/2;
            out = .5*powerlooutsqrted*lo;
        } 
		else {
			t_real powerlooutsqrted = sqrt(powerlo);
			out = .5*powerlooutsqrted*lo;
		}

		outputSignals[0]->bufferPut((t_complex) out);
>>>>>>> AnaLuisa

	}
>>>>>>> 526292907dd2ff7d6ea618152856721b6b80e5dd
=======

>>>>>>> Romil
	return true;
}
