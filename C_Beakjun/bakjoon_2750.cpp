#include <stdio.h>

int arr[1001];

int main(void) {
    int num, i, j, min, idx, temp;
    scanf("%d", &num);
    for(i=0; i<num; i++) {
        scanf("%d", &arr[i]);
    }

    for(i=0; i< num; i++) {
        min = 1001;
        for(j =i ; j < num; j++) {
            if (min > arr[j]) {
                min = arr[j];
                idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    for(i=0; i<num; i++) {
        printf("%d\n", arr[i]);
    }
}