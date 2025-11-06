#include <iostream>
#include <algorithm>

using namespace std;

// int main(void) {
//     int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
//     sort(a, a+10); // sort(배열, 배열이 끝나는 시점)
//     for(int i = 0; i< 10; i++){
//         cout << a[i];
//     }
// }

bool compare(int a, int b) {
    return a > b;
    // b가 a 보다 작을때 우선 정렬
    // 내림차순 정렬
}

int main(void) {
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a+10, compare); // sort(배열, 배열이 끝나는 시점)
    for(int i = 0; i< 10; i++){
        cout << a[i] << ' ';
    }
}
