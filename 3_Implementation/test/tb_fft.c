#include "unity.h"
#include "fft.h"

void setUp(){}

void tearDown(){}

int length;
float * ditfft;

void test_fft_arbitrary_length(void){

    length = 2;
    float input1[] = {1,0,1,0};
    ditfft = fft(length, input1);
    float output1[2*length];
    for (int i = 0; i < 2*length; i++){
        output1[i] = ditfft[i];
    }
    float expectedoutput1[] = {2,0,0,0};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput1, output1, 2*length);

    length = 8;
    float input2[] = {0.5,0,0.5,0,0.5,0,0.5,0,0,0,0,0,0,0,0,0};
    ditfft = fft(length, input2);
    float output2[2*length];
    for (int i = 0; i < 2*length; i++){
        output2[i] = ditfft[i];
    }
    float expectedoutput2[] = {2,0.000000,0.5,-1.207107,0,0.000000,0.5,-0.207107,0,0.000000,0.5,0.207107,0,0.000000,0.5,1.207107};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput2, output2, 2*length);

}

void test_fft_real(void){

    length = 4;
    float input[] = {1,0,-1,0,1,0,-1,0};
    ditfft = fft(length, input);
    float output[2*length];
    for (int i = 0; i < 2*length; i++){
        output[i] = ditfft[i];
    }
    float expectedoutput[] = {0.000000,0.000000,0.000000,0.000000,4.000000,0.000000,0.000000,0.000000};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output, 2*length);

}

void test_fft_complex(void){

    length = 4;
    float input[] = {0,1,0,0,0,-1,0,0};
    ditfft = fft(length, input);
    float output[2*length];
    for (int i = 0; i < 2*length; i++){
        output[i] = ditfft[i];
    }
    float expectedoutput[] = {0.000000,0.000000,0.000000,2.000000,0.000000,0.000000,0.000000,2.000000};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output, 2*length);

}

void test_fft_even_symmetry(void){

    length = 4;
    float input[] = {-1,1,0,0,1,1,0,0};
    ditfft = fft(length, input);
    float output[2*length];
    for (int i = 0; i < 2*length; i++){
        output[i] = ditfft[i];
    }
    float expectedoutput[] = {0.000000,2.000000,-2.000000,0.000000,0.000000,2.000000,-2.000000,0.000000};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output, 2*length);

}

void test_fft_odd_symmetry(void){

    length = 4;
    float input[] = {-1,-1,0,0,1,1,0,0};
    ditfft = fft(length, input);
    float output[2*length];
    for (int i = 0; i < 2*length; i++){
        output[i] = ditfft[i];
    }
    float expectedoutput[] = {0.000000,0.000000,-2.000000,-2.000000,0.000000,0.000000,-2.000000,-2.000000};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output, 2*length);

}

int main(void){

    UNITY_BEGIN();

    RUN_TEST(test_fft_arbitrary_length);
    RUN_TEST(test_fft_real);
    RUN_TEST(test_fft_complex);
    RUN_TEST(test_fft_even_symmetry);
    RUN_TEST(test_fft_odd_symmetry);

  return UNITY_END();

}

