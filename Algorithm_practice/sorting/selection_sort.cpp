// 선택 정렬
#include <stdio.h>

int main(void) {
	int i, j, min, idx, temp;
	int arr[10] = { 1, 10, 5, 8 , 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > arr[j]){
				min = arr[j];
				idx = j;
				}
		}
		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}

// n*(n+1)/2 ��ŭ�� �ð��� �ɸ�
// O(N*N) ��� ǥ���. Ư�� �˰������� �� ����Ƚ���� ������ ��Ÿ��