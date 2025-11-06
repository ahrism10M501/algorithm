#include<stdio.h>

int num = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3,2, 9};

void quickSort(int *data, int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;
    int i = start +1;
    int j = end;
    int temp;

    // 엇갈릴 떄 까지 반복
    while(i <= j) {
        // 키 값보다 큰 값이 나올때까지 오른쪽으로 이동
        while(data[i] <= data[key]) {
            i++;
        }
        // 키 값보다 작은 값이 나올때까지 왼쪽으로 이동
        while(data[j] >= data[key] && j > start) {
            j--;
        }
        if(i > j) {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }
    quickSort(data, start, j-1);
    quickSort(data, j+1, end);
}

int main(void) {
    quickSort(data, 0, num-1);
    for (int i=0;i<num;i++) {
        printf("%d ", data[i]);
    }
}