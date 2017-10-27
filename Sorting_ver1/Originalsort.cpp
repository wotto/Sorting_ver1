#include "Originalsort.h"

void original_sort(vector<int> A,int n) {
	vector<int> B(n+1, 0);
	vector<int> C(n, 0);
	for (int i = 0; i < A.size();i++) {
		++B[A[i]];
	}
	int j = 0;
	for (int i = 1; i < B.size(); i++) {
		while (B[i] != 0) {
			C[j] = i;
			--B[i];
			++j;
		}
	}
	/*for (int i = 0; i < C.size(); i++) {
		cout << C[i] << ",";
	}*/
}