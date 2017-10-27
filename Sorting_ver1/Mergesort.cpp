#include "Mergesort.h"
#include "common.h"

void merge_sort(vector<int> A) // execute Mergesort
{
	auto it = A.begin();
	it = A.insert(it, 0); // add the top of the array "0" in order to make an array starting from A[1] to A[size]

	MERGESORT(A,A.size()-1);
	// testing
	/*for (int i = 1; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
	cout << "\n";*/
}

void MERGESORT(vector<int>& A, int size)  // execute sorting
{
	if (size == 1) return;  //if size == 1 the array is already sorted
	else {
		vector<int> B((size / 2) + 1);  // first half of A
		vector<int> C((size - (size / 2)) + 1);  // second half of A
		DevidetoHalf(A, B, C, size);  // devide A into B and C
		MERGESORT(B, size / 2);  // sort B
		MERGESORT(C, size - (size / 2));  // sort C
		MERGE(A, B, C, size);  // merge B and C to A
	}
}

void DevidetoHalf(vector<int>& A,vector<int>& B,vector<int>& C, int size)  // Devide A into B and C
{
	B[0] = 0;
	C[0] = 0;  // in order to make an array starting from B[1]
	for (int i = 1; i <= size; ++i) {
		if(i <= size / 2) B[i] = A[i];
		else C[i - (size / 2)] = A[i];
	}
}

void MERGE(vector<int>& A, vector<int>& B, vector<int>& C,int size)  // Merge B and C to A
{
	B.push_back(INT_MAX);
	C.push_back(INT_MAX);  //append one INT_MAX entry to both B and C (Substitution to Infinity)
	int i = 1;
	int j = 1;
	for (int k = 1; k <= size; ++k) // add value the bigger value of B and C to A
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