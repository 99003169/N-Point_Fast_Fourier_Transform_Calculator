/**
* @file fft.h
*
*/
#ifndef FFT_H_INCLUDED
#define FFT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using std::sin;

/**
* Calculates the FFT
* @param[in] Total number of samples in the data sequence and the input data sequence
* @return FFT of the input data sequence
*
*/
float * fft(int, float []);

#endif /* FFT_H_INCLUDED */
