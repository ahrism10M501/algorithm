// 최악의 경우에서 O(N*logN) 을 보장함
// 정확하게 반절로 가르므로..!
#include<stdio.h>

int arr[8] = {7, 6, 5, 8, 3, 9, 1, 4};
int num = 8;
int sorted[8];

void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle+1;
    int k = m;
    // 작은 순서대로 배열에 삽입
    while( i <= middle && j <= n) {
        if ( a[i] <= a[j] ) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if ( i > middle ) {
        for(int t=j; t<=n; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    else {
            for(int t=i; t<=middle; t++) {
                sorted[k] = a[t];
                k++;
            }
        }
        for(int t= m; t<=n; t++) {
            a[t] = sorted[t];
        }
}

void mergeSort(int a[], int m, int n) {
    if (m < n) { // 요소 리스트가 1보다 큰 경우
        int middle = (m+n)/2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
}

int main(void) {
    mergeSort(arr, 0, num-1);
    for(int i=0; i< num; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// 기존의 데이터를 담을 추가적인 배열 공간이 필요하단 점에서 메모리 활용이 비효율적이나 속도를 보장하므로 효율적이다.
