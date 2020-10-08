#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <fft.h>
#define PROJECT_NAME    "fft"

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

    float input2[] = {0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0};
    ditfft = fft(8, input2);
    CU_ASSERT_EQUAL(2, ditfft[0]);
    CU_ASSERT_EQUAL(2, ditfft[1]);
    CU_ASSERT_EQUAL(0, ditfft[2]);
    CU_ASSERT_EQUAL(0, ditfft[3]);
    CU_ASSERT(2.000000 == ditfft[4]);
    CU_ASSERT_EQUAL(2, ditfft[5]);
    CU_ASSERT_EQUAL(0, ditfft[6]);
    CU_ASSERT_EQUAL(0, ditfft[7]);
    CU_ASSERT_EQUAL(-2, ditfft[8]);
    CU_ASSERT_EQUAL(-2, ditfft[9]);
    CU_ASSERT_EQUAL(0, ditfft[10]);
    CU_ASSERT_EQUAL(0, ditfft[11]);
    CU_ASSERT_EQUAL(-2, ditfft[12]);
    CU_ASSERT_EQUAL(-2, ditfft[13]);
    CU_ASSERT_EQUAL(0, ditfft[14]);
    CU_ASSERT_EQUAL(0, ditfft[15]);

    float input1[] = {1,0,1,0};
    ditfft = fft(2, input1);
    CU_ASSERT_EQUAL(2, ditfft[0]);
    CU_ASSERT_EQUAL(0, ditfft[1]);
    CU_ASSERT_EQUAL(0, ditfft[2]);
    CU_ASSERT_EQUAL(0, ditfft[3]);

}

void test_fft_real(void) {

    float input[] = {1,0,-1,0,1,0,-1,0};
    ditfft = fft(4, input);
    CU_ASSERT_EQUAL(0, ditfft[0]);
    CU_ASSERT_EQUAL(0, ditfft[1]);
    CU_ASSERT_EQUAL(0, ditfft[2]);
    CU_ASSERT_EQUAL(0, ditfft[3]);
    CU_ASSERT_EQUAL(4, ditfft[4]);
    CU_ASSERT_EQUAL(0, ditfft[5]);
    CU_ASSERT_EQUAL(0, ditfft[6]);
    CU_ASSERT_EQUAL(0, ditfft[7]);

}

void test_fft_complex(void) {

	float input[] = {0,1,0,0,0,-1,0,0};
    ditfft = fft(4, input);
    CU_ASSERT_EQUAL(0, ditfft[0]);
    CU_ASSERT_EQUAL(0, ditfft[1]);
    CU_ASSERT_EQUAL(0, ditfft[2]);
    CU_ASSERT_EQUAL(2, ditfft[3]);
    CU_ASSERT_EQUAL(0, ditfft[4]);
    CU_ASSERT_EQUAL(0, ditfft[5]);
    CU_ASSERT_EQUAL(0, ditfft[6]);
    CU_ASSERT_EQUAL(2, ditfft[7]);

}

void test_fft_even_symmetry(void) {

    float input[] = {-1,1,0,0,1,1,0,0};
    ditfft = fft(4, input);
    CU_ASSERT_EQUAL(0, ditfft[0]);
    CU_ASSERT_EQUAL(2, ditfft[1]);
    CU_ASSERT_EQUAL(-2, ditfft[2]);
    CU_ASSERT_EQUAL(0, ditfft[3]);
    CU_ASSERT_EQUAL(0, ditfft[4]);
    CU_ASSERT_EQUAL(2, ditfft[5]);
    CU_ASSERT_EQUAL(-2, ditfft[6]);
    CU_ASSERT_EQUAL(0, ditfft[7]);

}

void test_fft_odd_symmetry(void) {

    float input[] = {-1,-1,0,0,1,1,0,0};
    ditfft = fft(4, input);
    CU_ASSERT_EQUAL(0, ditfft[0]);
    CU_ASSERT_EQUAL(0, ditfft[1]);
    CU_ASSERT_EQUAL(-2, ditfft[2]);
    CU_ASSERT_EQUAL(-2, ditfft[3]);
    CU_ASSERT_EQUAL(0, ditfft[4]);
    CU_ASSERT_EQUAL(0, ditfft[5]);
    CU_ASSERT_EQUAL(-2, ditfft[6]);
    CU_ASSERT_EQUAL(-2, ditfft[7]);

}
