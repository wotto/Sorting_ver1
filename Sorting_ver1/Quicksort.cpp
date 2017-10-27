#include "Quicksort.h"

void quick_sort(vector<int> A) // execute Quicksort
{
	auto it = A.begin();
	it = A.insert(it, 0); // add the top of the array "0" in order to make an array starting from A[1] to A[size]

	QUICKSORT(A, 1, A.size() - 1);  // sort A[1...size]

	// testing
	/*for (int i = 1; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
	cout << "\n";*/
}

int PARTITION(vector<int>& A, int p, int r)  // execute partitation
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void QUICKSORT(vector<int>& A, int p, int r) // execute sorting
{
	if (p < r) {
		int q = PARTITION(A, p, r);  // A[p...q-1] <= A[q] and A[q+1...r] >= A[q]
		QUICKSORT(A, p, q - 1);  // sort A[p...q-1]
		QUICKSORT(A, q + 1, r);  // sort A[q+1...r]
	}
}