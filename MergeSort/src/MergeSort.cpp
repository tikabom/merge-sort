//============================================================================
// Name        : MergeSort.cpp
// Author      : tika
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MergeSort.hpp"

using namespace std;

void MergeSort::merge(
		int* array,
		long int lStart,
		long int lEnd,
		long int rStart,
		long int rEnd,
		int* sorted) {

	int i, j, k;
	i = lStart;
	j = rStart;

	for(k = lStart; k <= rEnd; k++) {
		if(j > rEnd) {
			sorted[k] = array[i++];
		}
		else if(i > lEnd) {
			sorted[k] = array[j++];
		}
		else if(array[i] <= array[j]) {
			sorted[k] = array[i++];
		}
		else {
			sorted[k] = array[j++];
		}
	}

	for(k = lStart; k <= rEnd; k++) {
		array[k] = sorted[k];
	}
}

void MergeSort::sort(
		int* array,
		long int start,
		long int end,
		int* sorted) {
	long int n = end - start + 1;

	if(n == 1) {
		return;
	}

	MergeSort::sort(array, start, start + n/2 - 1, sorted);
	MergeSort::sort(array, start + n/2, end, sorted);
	MergeSort::merge(
			array, start, start + n/2 - 1,
			start + n/2, end, sorted);
}

int* MergeSort::merge2(int* left, int* right, long lSize, long rSize) {
	int i,j,k;
	i = j = 0;

	int* array = new int[lSize + rSize];

	for(k = 0; k < lSize + rSize; k++) {
		if(j == rSize) {
			array[k] = left[i++];
		}
		else if(i == lSize) {
			array[k] = right[j++];
		}
		else if(left[i] < right[j]) {
			array[k] = left[i++];
		}
		else {
			array[k] = right[j++];
		}
	}

	return array;
}

int* MergeSort::sort2(int* array, long n) {
	if(n == 1) {
		return array;
	}
	long lSize;
	if(n % 2 != 0) {
		lSize = n/2 + 1;
	}
	else {lSize = n/2;}

	int* left = new int[lSize];
	int* right = new int[n/2];

	int i,j;

	j = 0;
	for(i = 0; i < lSize; i++) {
		left[j++] = array[i];
	}

	j = 0;
	for(i = lSize; i < n; i++) {
		right[j++] = array[i];

	}

	left = MergeSort::sort2(left, lSize);
	right = MergeSort::sort2(right, n/2);
	return MergeSort::merge2(left, right, lSize, n/2);
}
