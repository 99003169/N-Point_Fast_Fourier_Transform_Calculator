## Description
“Fast Fourier Transform (FFT) is the most important numerical algorithm of our lifetime”, says Gilbert Strang. 

It is a computer algorithm which changes the time domain signal into the frequency domain by quickly performing a discrete Fourier transform (DFT) on the signal. There are myriad uses of FFT namely in engineering, music, science, and mathematics.

For instance, it is used in digital signal processing (DSP) to modify, filter and decode digital audio, video and images. It is the foundation for voice recognition and myriad other pattern recognition and image compression applications. 

A live example would be, noise-cancelling headphones using FFT to turn unwanted sounds into simple waves so that inverse signals can be generated to cancel them or FFTs being used to sharpen edges and create effects in static images. 

Considering the extreme importance of the FFT algorithm in the industry, this project focusses on the implementation of the Cooley-Tukey FFT algorithm, to convert a digital signal (x) with length (N) from the time domain into a signal in the frequency domain (X). This is commonly known as the N-point radix-2 DIT FFT. The N-point FFT is written in the C programming language and it takes the values of the signal sequence as user inputs along with the value of N. The output would be a discrete Fourier transformed sequence of values corresponding to the user input sequence. In short, the output would be the FFT of the user input data sequence. 
