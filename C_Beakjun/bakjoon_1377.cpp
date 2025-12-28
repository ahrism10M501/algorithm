#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void bbsort(int A[], int N) {
    bool changed = false;

    for(int i=1; i<=N+1; i++) {
        changed = false;
        for (int j=1; j<=N-i; j++) {
            if (A[j] > A[j+1]) {
                changed = true;
                swap(A[j], A[j+1]);
            }
        }
        if (changed == false) {
            cout << i << '\n';
            break;
            // The array is already sorted
            // 'i' represents the number of passes completed
            // this is bubble sort with early exit to avoid unnecessary N^2 iterations
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    for(int i=0; i<N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int max = 0;
    for(int i=0; i<N; ++i) {
        int diff = A[i].second - i;
        if(max < diff) {
            max = diff;
        }
    }

    cout << max + 1;

    return 0;
}