// finding the count of the good number within the number set N
// Good number?
// A number that can be expressed as the sum of two otgher distinct numbers.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> A(N, 0);

    for(int i=0;i<N;++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int count = 0;
    for(int k=0;k<N;++k) {
        long find = A[k];
        int i = 0;
        int j = N-1;
        while(i<j) {
            if (i==k) {
                i++;
                continue;
            }
            if (j==k) {
                j--;
                continue;
            }
            long sum = (long)A[i] + A[j];
            if(sum == find) {
                if(i != k && j != k) {
                    count++;
                    break;
                }
            } else if (sum < find) {
                i++;
            } else {
                j--;
            }
        }
    }
    cout << count << endl;
    return 0;
}