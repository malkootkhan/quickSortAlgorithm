
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* quick sort algorithm implementation in C */
#include <stdio.h>
#include <stdlib.h>

#define FIRST_INDEX	0

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quickSort(int *arr, int l, int r) {
	int loc = l;
	int left = l;
	int right = r;
	while (left < right) {
		//right sorting
		do
		{
			if (arr[loc] > arr[right]) {
				swap(&arr[loc], &arr[right]);
				loc = right;
				break;
			}
			right--;
		} while (arr[loc] < arr[right]);

		//left sorting
		do
		 {
			if (arr[loc] < arr[left]) {
				swap(&arr[loc], &arr[left]);
				loc = left;
				break;
			}
			left++;
		}while (arr[loc] > arr[left]);

	}

	if ( (r - (loc-1)) >= 2)
		quickSort(arr, loc+1, r);	//recusive call for doing the same thing for sub arrays left and right of pivot element 'loc'
	else if (loc - 1 >= 2)
		quickSort(arr, 0, loc - 1);
	else
		return;
}
void display(int *arr, int size) {
	for (int index = FIRST_INDEX; index < size; index++)
		printf("%d ", arr[index]);
}
int main() {
	int testArray[] = {65,45,17,43,80,37,10,72,15};
	int sizeOfArr = (sizeof(testArray) / 4);

	printf("Before Sorting...\n");
	display(testArray, sizeOfArr);
	
	quickSort(testArray, FIRST_INDEX, sizeOfArr - 1);

	printf("\nAfter Sorting....\n");
	display(testArray, sizeOfArr);

	return 0;
}

