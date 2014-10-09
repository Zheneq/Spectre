#include <stdlib.h>
#include <stdio.h>
#include <fftw3.h>
#include <math.h>
#include "Fourier.h"

buffer buf[2];


double energy, E_0, step;
int implen, len;

enum functions
{
	FUNC_None,
	FUNC_Jump,
	FUNC_Linear,
	FUNC_Gauss,
	FUNC_Sine
};

double parameter;
void function(functions func, int left_b, int right_b, int index){

	if (func == FUNC_Sine){
		for (int i = left_b; i < right_b; i++){
			buf[index].imp[i] = sin((double)(i-left_b));
		}
	}

	if (func == FUNC_None){
		for (int i = left_b; i < right_b; i++){
			buf[index].imp[i] = 0;
		}
	}

	if (func == FUNC_Linear){
		for (int i = left_b; i < right_b; i++){
			buf[index].imp[i] = (-(i-right_b)) * (left_b-right_b);
		}
	}

	if (func == FUNC_Gauss){
		for (int i = left_b; i < right_b; i++){
			buf[index].imp[i] = exp(-pow(((i-left_b)/parameter),2));
		}
	}

	if (func == FUNC_Jump){
		for (int i = left_b; i < right_b; i++){
			buf[index].imp[i] = 0.0;
		}
	}

}



void add_energy(){

	int length = (E_0 - energy)/step;
	for(int i = 0; i < size/2; i++){
		if ((i + length/2) < size/2){
			buf.imp[i] = buf.imp[i+length/2];
		}
	}

	for(int i = size; i > size/2; i--){
		if ((i - length/2) > size/2){
			buf.imp[i] = buf.imp[i-length/2];
		}
	}

	for(int i = (size/2 - length/2); i < (size/2 + length/2); i++){
		buf.imp[i] = 1.0;
	}



}

void check_energy(){

	energy = 0.0;

	for (int i = 0; i < buf.len; i++){
		energy += buf.imp[i]*buf.imp[i];
	}

	if ((E_0 - energy) > 0){
		add_energy();
	}
}

void generate_gauss(double param){

	for (int i = 0; i < buf.len; i++){

		buf.imp[i] = exp(-((i-buf.len/2)*(i-buf.len/2)/(param*param)));
	}
}