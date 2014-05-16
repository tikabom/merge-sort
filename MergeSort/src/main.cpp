/* Merge Sort:
 * (1) using O(n) space complexity
 * (2) using O(n^2) space complexity
 * and O(nlogn) time complexity
 * main.cpp
 *
 *  Created on: May 14, 2014
 *      Author: tika
 */

#include <iostream>
#include <cstdlib>
#include "MergeSort.hpp"

using namespace std;

int main() {
	long int n = 27;
	int* array = new int[n];
	int i;

	srand(time(NULL));

	for(i = 0; i < n; i++) {
		array[i] = 1 + (rand() % 20);
		cout << array[i] << " ";
	}
	cout << endl;

	int* sorted = new int[n];

	MergeSort* mergeSort = new MergeSort();

	/*
	 * (1) using O(n) space complexity
	 */
	mergeSort->sort(array, 0, n - 1, sorted);

	for(i = 0; i < n; i++) {
		cout << sorted[i] << " ";
	}
	cout<<endl;

	/*
	 * using O(n^2) space complexity
	 */
	array = mergeSort->sort2(array, n);
	for(i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}


