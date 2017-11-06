// Sorting.cpp : Defines the entry point for the console application.
//

#include "common.h"
#include "Heapsort.h"
#include "Quicksort.h"
#include "Insertionsort.h"
#include "Mergesort.h"
#include "Originalsort.h"

int main()
{
	const int n = 10000; // the size of array

	// test test test

	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rand(1,n);  // generate random value from 1 to n 

	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		A[i] = rand(mt);
	}

	// testing
	/*for (int i = 0; i < n; ++i) {
		cout << A[i] << ",";
	}
	cout << "\n";*/  

	// testing for the original sort
	//vector<int> A = { 5,1,30000,2,3 };

	cout << "The length of the array is " << n << "\n";


	auto start = chrono::system_clock::now();
	insertion_sort(A);
	auto end = chrono::system_clock::now();
	auto ins_dur = end - start;
	auto ins_msec = chrono::duration_cast<chrono::milliseconds>(ins_dur).count();
	cout << "The processing time of INSERT SORT is " << ins_msec << "\n";
	
	start = chrono::system_clock::now();
	merge_sort(A);
	end = chrono::system_clock::now();
	auto mer_dur = end - start;
	auto mer_msec = chrono::duration_cast<chrono::milliseconds>(mer_dur).count();

	cout << "The processing time of MERGE SORT is " << mer_msec << "\n";

	start = chrono::system_clock::now();
	heap_sort(A);
	end = chrono::system_clock::now();
	auto hea_dur = end - start;
	auto hea_msec = chrono::duration_cast<chrono::milliseconds>(hea_dur).count();

	cout << "The processing time of HEAPSORT is " << hea_msec << "\n";

	start = chrono::system_clock::now();
	quick_sort(A);
	end = chrono::system_clock::now();
	auto qui_dur = end - start;
	auto qui_msec = chrono::duration_cast<chrono::milliseconds>(qui_dur).count();

	cout << "The processing time of QUICKSORT is " << qui_msec << "\n";

	start = chrono::system_clock::now();
	original_sort(A);
	end = chrono::system_clock::now();
	auto ori_dur = end - start;
	auto ori_msec = chrono::duration_cast<chrono::milliseconds>(ori_dur).count();

	cout << "The processing time of ORIGINALSORT is " << ori_msec << "\n";

	//cout << "The length of the array is " << n << "\n";
	//cout << "The processing time of INSERT SORT is " << ins_msec << "\n";
	//cout << "The processing time of MERGE SORT is " << mer_msec << "\n";
	//cout << "The processing time of HEAPSORT is " << hea_msec << "\n";
	//cout << "The processing time of QUICKSORT is " << qui_msec << "\n";
	//cout << "The processing time of ORIGINALSORT is " << ori_msec << "\n";

    return 0;
}