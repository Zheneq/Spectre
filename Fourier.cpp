#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Fourier.h"

buffer buf[2];

double E_0 = 300;
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
