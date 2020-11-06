# Test Plan

## 1. Test Strategy

### Test Scope

#### Features to be Tested

| Feature ID	                         |Description                                              |
|--------------------------------------|---------------------------------------------------------|
| FW01	                               | Input samples can be of arbitrary lengths.              |
| FW02	                               | Inputs samples can be real or complex valued.           |
| FW03	                               | Input samples can be of even symmetry or odd symmetry.  |

#### Features not to be Tested

| Feature ID	                         | Description                                                          |
|--------------------------------------|----------------------------------------------------------------------|
| FW04	                               | The FFT output should be displaced in a neat and unambiguous manner. |
| FW05	                               | Inputs shall be valid.                                               |

### Test Type

* Unit Testing: To test the smallest piece of verifiable software in the application.
* System Test: Conducted on a complete, integrated system to evaluate the systems compliance with its specified requirements.

## 2. Test Objective

The objective of the test is to find as many software defects as possible, thus to ensure that the software under test is bug free before release. Here, the program should be able to compute an error free FFT output sequence for any arbitrary length of the user input, for real / complex input data and for even or odd datasets. 

## 3. Test Criteria

### Suspension Criteria

* If 40% of test cases failed, testing is suspended until the previous cases are fixed.

### Exit Criteria

* Run rate - 100%
* Pass rate - greater than or equal to 90%.

## 4. Test Environment

* The test is carried out using CUnit – A unit test framework.

## 5. Test Cases

| Test Case ID 	  | Test Scenario	                                                        | Test Steps	                                    | Test Data                        |
|-----------------|-----------------------------------------------------------------------|-------------------------------------------------|----------------------------------|
| TC01	          | Test whether the FFT is computed for arbitrary length of inputs.	    | 1.Enter the no. of samples.                     | 1. 8                             |
|                 |                                                                       | 2. Enter the samples.                           | 2. 0, j, 0, 1, 0, j, 0, 1        |
|                 |                                                                       | 1. Enter a different no. of samples.	          | 1. 2                             |
|                 |                                                                       | 2. Enter the samples again.                     | 2. 1, 1                          |
| TC02	          | Test whether the FFT is computed for real numbers.	                  | 1. Enter the no. of samples.                    | 1. 4                             |
|                 |                                                                       | 2. Enter real samples.	                        | 2. 1, -1, 1, -1                  |
| TC03	          | Test whether the FFT is computed for complex numbers.	                | 1. Enter the no. of samples.                    | 1. 4                             |
|                 |                                                                       | 2. Enter complex samples.	                      | 2. j, 0, -j, 0                   |
| TC04	          | Test whether the FFT is computed for data samples with even symmetry.	| 1. Enter the no. of samples.                    | 1. 4                             |
|                 |                                                                       | 2. Enter even data samples.                     | 2. -1+1j, 0, 1+j, 0              |
| TC05	          | Test whether the FFT is computed for data samples with odd symmetry.	| 1. Enter the no. of samples.                    | 1. 4                             |
|                 |                                                                       | 2. Enter odd data samples.                      | 2. -1-1j, 0, 1+j, 0

## 6. Output - Test Case Run Summary

![Output](https://github.com/stepin105296/N-Point_Fast_Fourier_Transform_Calculator/blob/master/MiniProject_C/4_TestPlanAndOutput/Test%20Case%20Run%20Summary.png)
