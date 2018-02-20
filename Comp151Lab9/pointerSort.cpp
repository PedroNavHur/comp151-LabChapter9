/// Comp 151 - Pointer Sort
// @author: Pedro Navarrete
// v1.00 

#include <iostream>
using namespace std;

void getArr(float *arr, int n); // gets the array values
void sort(float *arr, int n); // sort the array using bubble sort
float average(float *arr, int n); // gets the array average
void showArr(float *arr, int n); // outputs the array

int main() {

	float *score;
	int score_number;

	// gets the number of scores
	cout << "Please input the number of scores" << endl;
	cin >> score_number;
	cout << endl;

	// allocate the array space
	score = new float[score_number];

	// check if there was a memory error
	if (!score) {
		cout << "Error allocating memory!\n";
		return 1;
	}

	// gets scores array
	getArr(score, score_number);

	// sorts the array in ascending order
	sort(score, score_number);

	// display the average of scores
	cout << "\nThe average of the scores is " << average(score, score_number) << endl;

	// display the array sortered
	cout << "\nHere are the scores in ascending order\n";
	showArr(score, score_number);

	// deallocates de array
	delete[] score;
}

// gets the array values
void getArr(float *arr, int n) {
	for (size_t i = 0; i < n; i++) {
		cout << "Please enter a score" << endl;
		cin >> *(arr + i);
	}
}

// sort the array in ascending order using bubble sort
void sort(float *arr, int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

// gets the array average
float average(float *arr, int n) {
	float sum = 0;
	for (size_t i = 0; i < n; i++) {
		sum += *(arr + i);
	}
	return (sum / n);
}

// outputs the array
void showArr(float *arr, int n) {
	for (size_t i = 0; i < n; i++) {
		cout << *(arr + i) << endl;
	}
}