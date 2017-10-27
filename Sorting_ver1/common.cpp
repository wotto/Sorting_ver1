#include "common.h"

void swap(int *a, int *b) {  //swap the value of a and b
	int c;
	c = *a;
	*a = *b;
	*b = c;
	return;
}