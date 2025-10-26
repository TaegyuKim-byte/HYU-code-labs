#include <stdio.h>

void swap(int* a, int* b) {
	int tmp;
	if (*a > *b) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void print_arr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}


void sort(int* arr, int len) {
	int i, tmp;
	if (len == 1) {
		return;
	} else {
		sort(arr + 1, len - 1);
		for (i = 1, tmp = arr[0]; i < len; i++) {
			if (tmp > arr[i]) {
				swap(&arr[i-1], &arr[i]);
			} else {
				break;
			}
		}
	}
}

int main(void) {
	int arr[] = {1, 4, 8, 3, 7, 2, 6, 5};
	sort(arr, sizeof(arr) / sizeof(arr[0]));
	print_arr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}




