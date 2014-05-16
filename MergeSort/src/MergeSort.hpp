/*
 * MergeSort.hpp
 *
 *  Created on: May 14, 2014
 *      Author: tika
 */

#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

class MergeSort {
public:
	void merge(
			int* array,
			long int lStart,
			long int lEnd,
			long int rStart,
			long int rEnd,
			int* sorted);
	void sort(
			int* array,
			long int start,
			long int end,
			int* sorted);
	int* merge2(int* left, int* right, long lSize, long rSize);
	int* sort2(int* array, long n);
};

#endif /* MERGESORT_HPP_ */
