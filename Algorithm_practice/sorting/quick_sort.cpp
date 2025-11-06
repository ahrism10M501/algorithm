#include <stdio.h>

int main(void) {
    int arr[10] = {3, 2, 1, 4, 7, 6, 10, 5, 8, 9};
    int pivot, temp;
    
    for(pivot=0; pivot<9; pivot++) {
        int i = pivot;
        int j = 9;

        while(i<j) {
            while(arr[pivot]>arr[i]) {
                i++;
            }
            while(arr[pivot]<arr[j]) {
                j--;
            }
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        temp = arr[pivot];
        arr[pivot] = arr[i];
        arr[i] = temp;
    }
    
    for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

    return 0;
}
