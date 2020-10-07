# Test Plan


## 1. Test Strategy


### Test Scope


#### Features to be Tested

| Feature ID	                         |Description
|--------------------------------------|---------------------------------------------------------
| FW01	                               | Input samples can be of arbitrary lengths. 
| FW02	                               | Inputs samples can be real or complex valued.
| FW03	                               | Input samples can be of even symmetry or odd symmetry.


#### Features not to be Tested

| Feature ID	                         | Description
|--------------------------------------|---------------------------------------------------------
| FW04	                               | The FFT output should be displaced in a neat and unambiguous manner.
| FW05	                               | Inputs shall be valid.


### Test Type

* Unit Testing: To test the smallest piece of verifiable software in the application.
* System Test: Conducted on a complete, integrated system to evaluate the systems compliance with its specified requirements.


## 2. Test Objective

The objective of the test is to find as many software defects as possible, thus to ensure that the software under test is bug free before release. Here, the program should be able to compute an error free FFT output sequence for any arbitrary length of the user input, for real / complex input data and for even or odd datasets. 



## 3. Test Criteria

### Suspension Criteria

If 40% of test cases failed, testing is suspended until the previous cases are fixed.

### Exit Criteria

Run rate - 100%
Pass rate - greater than or equal to 90%.


## 4. Test Environment

The test is carried out using Unity – A unit test framework.
