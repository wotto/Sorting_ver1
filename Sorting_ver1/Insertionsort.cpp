#include "common.h"
#include "Insertionsort.h"

void insertion_sort(vector<int> A) // execute Insertionsort
{
	auto it = A.begin();
	it = A.insert(it, 0); // add the top of the array "0" in order to make an array starting from A[1] to A[size]

	int element = 0;
	int i = 0;
	for (int j = 2; j < A.size() ; j++) { // A.size == real size + 1 (because of A[0])
		element = A[j];
		i = j - 1;
		while (i > 0 && A[i] > element) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = element;
	}

	// testing
	/*for (int i = 1; i < A.size(); i++)
	{
		cout << A[i] << ",";
	}
	cout << "\n";*/
}