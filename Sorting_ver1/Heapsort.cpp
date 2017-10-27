#include "Heapsort.h"


void heap_sort(vector<int> A) // execute Heapsort
{
	const int orisize = A.size();  // record the first size of A
	int size = A.size();

	auto it = A.begin();
	it = A.insert(it, 0); // add the top of the array "0" in order to make an array starting from A[1] to A[size]

	BUILD_MAX_HEAP(A,orisize); // build MaxHeap

	for (int i = orisize; i > 1; i--) {
		swap(A[1], A[i]);
		size--;
		MAX_HEAPIFY(A, 1, size);
	}
	// testing
	/*for (int i = 1; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
	cout << "\n";*/
}

void BUILD_MAX_HEAP(vector<int> &A,int size) {
	for (int i = size / 2; i > 0; i--){
		MAX_HEAPIFY(A, i, size);
	}
	return;
}

void MAX_HEAPIFY(vector<int>& A, int i, int size) {
	int l = 2 * i;
	int r = l + 1;
	int largest = 0;
	if (l <= size && A[l] > A[i])largest = l;
	else largest = i;
	if (r <= size && A[r] > A[largest]) largest = r;
	if (largest != i) {
		swap(A[i], A[largest]);
		MAX_HEAPIFY(A, largest, size);
	}
	return;
}
