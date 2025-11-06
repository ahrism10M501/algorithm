// quick sort로는 안 되는걸
#include <stdio.h>

int arr[1000000], num;

void quickSort(int *data, int start, int end) {
    if (start >= end) return;
    int key = start, i = start + 1, j = end, temp;

    while (i <= j) {
        while (i <= end && data[i] <= data[key]) i++;
        while (j > start && data[j] >= data[key]) j--;
        if (i < j) {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    temp = data[j];
    data[j] = data[key];
    data[key] = temp;

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main(void) {
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, num - 1);

    for (int i = 0; i < num; i++) {
        printf("%d\n", arr[i]);
    }
}
