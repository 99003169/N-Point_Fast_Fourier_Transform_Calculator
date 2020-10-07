/**
* @file main.c
*
*/

#include "fft.h"

/**
*Main entry of the program
*/

int main(){

    int N, k;
    printf("\n\t\tWelcome to Radix-2 DIT FFT Calculator!!\n\n");

    //accept sample count
    while(1){
        printf("\n\tEnter total number of samples\t(Make sure it is a power of 2):\t");
        scanf("%d", &N);

        //Checking whether the sample count is a power of 2
        if((N & (N-1)) != 0){
            printf("\n\tThe sample count should be a power of 2! Please try again.\n");
            continue;
        }
        else{
            break;
        }
    }

    //accept input data sequence
    float data[2*N];
    printf("\n\tEnter input data sequence\t(Make sure the real and imaginary part are separated by 2 tabs):\n\n");
    printf("\t\tINPUT\n");
    printf("\n\tReal Part\tImaginary Part\n\n");
    for (k = 0; k < 2*N; k += 2){
        printf("\t");
        scanf("%f\t\t%f", &data[k], &data[k+1]);
    }

    //call fft()
    float * ditfft = fft(N, data);

    //display output data sequence
    printf("\n\t\tFFT OUTPUT\n");
    printf("\n\tReal Part\tImaginary Part\n\n");
    for (k = 0; k < 2*N; k += 2){
        printf("\t%f\t%f\n", ditfft[k], ditfft[k+1]);
    }

    return 0;

}

