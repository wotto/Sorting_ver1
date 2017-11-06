#include "Mergesort.h"
#include "common.h"

void merge_sort(vector<int> A) // execute Mergesort
{
	auto it = A.begin();
	it = A.insert(it, 0); // add the top of the array "0" in order to make an array starting from A[1] to A[size]

	MERGESORT(A, 1, A.size()-1);
	// testing
	/*for (int i = 1; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
	cout << "\n";*/
}

void MERGESORT(vector<int>& A, int left, int right)  // execute sorting
{
	int size = right - left + 1;
	if (size == 1) return;  //if size == 1 the array is already sorted
	else {
		MERGESORT(A, left, (left + right) / 2);  // sort B
		MERGESORT(A, (left + right) / 2 + 1, right);  // sort C
		MERGE(A, left, (left + right) / 2, right);  // merge B and C to A
		return;
	}
}


void MERGE(vector<int>& A, int left, int mid,int right)  // Merge B and C to A
{
	vector<int> B(mid - left + 1, 0);
	vector<int> C(right - mid, 0);
	for (int i = 0; i < B.size(); ++i) {
		B[i] = A[left + i];
	}
	for (int i = 0; i < C.size(); ++i) {
		C[i] = A[mid + 1 + i];
	}
	B.push_back(INT_MAX);
	C.push_back(INT_MAX);  //append one INT_MAX entry to both B and C (Substitution to Infinity)
	int i = 0;
	int j = 0;
	for (int k = left; k <= right; ++k) // add value the bigger value of B and C to A
	{
		if (B[i] <= C[j]) {
			A[k] = B[i];
			++i;
		}
		else {
			A[k] = C[j];
			++j;
		}
	}
}