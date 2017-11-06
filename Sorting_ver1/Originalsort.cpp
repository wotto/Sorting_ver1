#include "Originalsort.h"

void original_sort(vector<int> A) {
	int n = 0;
	for (int i = 0; i < A.size(); ++i) {
		if (n < A[i]) n = A[i];
	}

	vector<int> B(n, 0);
	vector<int> C(A.size() , 0);
	for (int i = 0; i < A.size();i++) {
		++B[A[i] - 1];
	}
	int j = 0;

	for (int i = 0; i < B.size(); i++) {
		while (B[i] != 0) {
			C[j] = i + 1;
			--B[i];
			if (j + 1 >= n)
			{
				break;
			}
			++j;
		}
	}

	//testing
	for (int i = 0; i < C.size(); i++) {
		cout << C[i] << ",";
	}
}