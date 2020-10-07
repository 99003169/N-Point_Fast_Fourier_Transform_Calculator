#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <fft.h>
#define PROJECT_NAME    "fft"

int length;
float * ditfft;

void test_fft_arbitrary_length(void);
void test_fft_real(void);
void test_fft_complex(void);
void test_fft_even_symmetry(void);
void test_fft_odd_symmetry(void);

int main() {

	if (CUE_SUCCESS != CU_initialize_registry())
    		return CU_get_error();
  	CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);

	CU_add_test(suite, "fft_arbitrary_length", test_fft_arbitrary_length);
	CU_add_test(suite, "fft_real", test_fft_real);
	CU_add_test(suite, "fft_complex", test_fft_complex);
	CU_add_test(suite, "fft_even_symmetry", test_fft_even_symmetry);
	CU_add_test(suite, "fft_odd_symmetry", test_fft_odd_symmetry);

  	CU_basic_set_mode(CU_BRM_VERBOSE);
  
	CU_basic_run_tests();
  
	CU_cleanup_registry();

  	return 0;
}
 
void test_fft_arbitrary_length(void) {
	length = 2;
    	float input1[] = {1,0,1,0};
    	ditfft = fft(length, input1);
    	float output1[2*length];
    	for (int i = 0; i < 2*length; i++){
        	output1[i] = ditfft[i];
    	}
    	float expectedoutput1[] = {2,0,0,0};
    	CU_ASSERT_EQUAL(expectedoutput1, output1, 2*length);

    	length = 8;
    	float input2[] = {0.5,0,0.5,0,0.5,0,0.5,0,0,0,0,0,0,0,0,0};
    	ditfft = fft(length, input2);
    	float output2[2*length];
    	for (int i = 0; i < 2*length; i++){
        	output2[i] = ditfft[i];
    	}
    	float expectedoutput2[] = {2,0.000000,0.5,-1.207107,0,0.000000,0.5,-0.207107,0,0.000000,0.5,0.207107,0,0.000000,0.5,1.207107};
    	CU_ASSERT_EQUAL(expectedoutput2, output2);
}

void test_fft_real(void) {
	length = 4;
    	float input[] = {1,0,-1,0,1,0,-1,0};
    	ditfft = fft(length, input);
    	float output[2*length];
    	for (int i = 0; i < 2*length; i++){
        	output[i] = ditfft[i];
    	}
    	float expectedoutput[] = {0.000000,0.000000,0.000000,0.000000,4.000000,0.000000,0.000000,0.000000};
    	CU_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output);
}

void test_fft_complex(void) {
	length = 4;
	float input[] = {0,1,0,0,0,-1,0,0};
    	ditfft = fft(length, input);
    	float output[2*length];
    	for (int i = 0; i < 2*length; i++){
        	output[i] = ditfft[i];
    	}
    	float expectedoutput[] = {0.000000,0.000000,0.000000,2.000000,0.000000,0.000000,0.000000,2.000000};
    	CU_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output);
}

void test_fft_even_symmetry(void) {
  	length = 4;
    	float input[] = {-1,1,0,0,1,1,0,0};
    	ditfft = fft(length, input);
    	float output[2*length];
    	for (int i = 0; i < 2*length; i++){
        	output[i] = ditfft[i];
    	}
    	float expectedoutput[] = {0.000000,2.000000,-2.000000,0.000000,0.000000,2.000000,-2.000000,0.000000};
    	CU_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output);
}

void test_fft_odd_symmetry(void) {
  	length = 4;
    	float input[] = {-1,-1,0,0,1,1,0,0};
    	ditfft = fft(length, input);
    	float output[2*length];
    	for (int i = 0; i < 2*length; i++){
        	output[i] = ditfft[i];
    	}
    	float expectedoutput[] = {0.000000,0.000000,-2.000000,-2.000000,0.000000,0.000000,-2.000000,-2.000000};
    	CU_ASSERT_EQUAL_FLOAT_ARRAY(expectedoutput, output);
}
