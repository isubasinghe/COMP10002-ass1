#include <stdio.h>
void
float_swap(float *p1, float *p2) {
	float tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void
sort_int_array(float A[], int n) {
	int i, j;
	/* assume that A[0] to A[n-1] have valid values */
	for (i=1; i<n; i++) {
		/* swap A[i] left into correct position */
		for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
			/* not there yet */
			float_swap(&A[j], &A[j+1]);
		}
	}
	/* and that's all there is to it! */
}

int main() {
	float array[] = {43, 23, 45,67, 82, 34, 65, 23, 45, 67, 53, 26, 56};
	sort_int_array(array, 13);
	for(int i=0; i < 13; i++) {
		printf("%f\n", array[i]);
	}
}
