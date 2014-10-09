#include <stdlib.h>
#include <stdio.h>
#include <fftw3.h>
#include <math.h>
#include "Fourier.h"

buffer buf[2];


double *imp, *spec, energy, E_0, step;
int implen, speclen;

enum functions
{
	FUNC_None,
	FUNC_Jump,
	FUNC_Linear,
	FUNC_Gauss,
	FUNC_Sine
};

void function(functions func, int left_b, int right_b){

	if (func == FUNC_Sine){
		for (int i = left_b; i < right_b; i++){
			in[i] = sin(i-left_b);
		}
	}

	if (func == FUNC_None){
		for (int i = left_b; i < right_b; i++){
			in[i] = 0;
		}
	}

	if (func == FUNC_Linear){
		for (int i = left_b; i < right_b; i++){
			in[i] = (-(i-right_b)) * (left_b-right_b);
		}
	}

	if (func == FUNC_Gauss){
		for (int i = left_b; i < right_b; i++){
			in[i] = exp(-((i-left_b)/parameter)^2);
		}
	}

	if (func == FUNC_Jump){
		for (int i = left_b; i < right_b; i++){
			in[i] = 0.0;
		}
	}

}

void alloc(int size){

	static fftw_plan p1,p2;

	p1 = fftw_plan_dft_r2c_1d(speclen, imp, out, FFTW_ESTIMATE);

	p2 = fftw_plan_dft_r2c_1d(speclen, imp, out, FFTW_ESTIMATE);

	out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*(size));
}



void fourier(){

	fftw_execute(p1);

	for(i = 0; i < size/2 + 1; i++){

		spec[i] = (sqrt(out[i][0]*out[i][0]+out[i][1]*out[i][1]))/size;
	}

	fftw_execute(p2);

	for(i = 0; i < size/2 + 1; i++){

		spec[i] = (sqrt(out[i][0]*out[i][0]+out[i][1]*out[i][1]))/size;
	}

	fftw_free(out);
}

void add_energy(){

	int length = (E_0 - energy)/step;
	for(int i = 0; i < size/2; i++){
		if ((i + length/2) < size/2){
			imp[i] = imp[i+length/2];
		}
	}

	for(int i = size; i > size/2; i--){
		if ((i - length/2) > size/2){
			imp[i] = imp[i-length/2];
		}
	}

	for(int i = (size/2 - length/2); i < (size/2 + length/2); i++){
		imp[i] = 1.0;
	}



}

void check_energy(){

	energy = 0.0;

	for (int i = 0; i < size; i++){
		energy += imp[i]*imp[i];
	}

	if ((E_0 - energy) > 0){
		add_energy();
	}
}
//зависимость спектра от формы импульса