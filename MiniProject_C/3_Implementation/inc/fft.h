/**
* @file fft.h
*/
#ifndef FFT_H_INCLUDED
#define FFT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Calculates the FFT
* @param[in] N Total number of samples in the input data sequence
* @param[in] data[] An array containing the input data sequence
* @return data: A pointer pointing to an array containing the computed FFT
*/
float * fft(int, float []);

#endif /* FFT_H_INCLUDED */
