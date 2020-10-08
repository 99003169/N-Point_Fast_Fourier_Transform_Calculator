#include <fft.h>

#define SWAP(a,b) tempr=(a); (a)=(b); (b)=tempr

float * fft(int N, float data[]){

    //variable declaration
    int i, j, m, n;

    //bit-reverse the input
    n = 2*N;
    j = 1;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            SWAP(data[j-1], data[i-1]);
            SWAP(data[j], data[i]);
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j +=m;
    }

    //Calculate FFT
    int istep, mmax = 2, isign = -1;
    float wtemp, tempr, tempi, wpr, wpi, wr, wi, theta;
    
    while (n > mmax) {
        istep = mmax << 1;
        theta = isign*(6.28318530717959/mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m = 1; m < mmax; m += 2) {
            for (i = m; i <= n; i += istep) {
                j = i + mmax;
                tempr = wr*data[j-1] - wi*data[j];
                tempi = wr*data[j] + wi*data[j-1];
                data[j-1] = data[i-1] - tempr;
                data[j] = data[i] - tempi;
                data[i-1] = data[i-1] + tempr;
                data[i] = data[i] + tempi;
            }
            wtemp = wr;
            wr += wtemp*wpr - wi*wpi;
            wi += wtemp*wpi + wi*wpr;
        }
        mmax = istep;
    }

    //return the fft computed
    return data;

}
