// S[i] = A[0] + A[2] + ... + A[i-1] + A[i]
#include <iostream>
#include <vector>
using namespace std;

void calcPrefixSum(const vector<int>& A, vector<int>& S) {
    if(A.empty()) return;
    S.resize(A.size());
    S[0] = A[0];

    for(size_t i=1; i< A.size(); ++i) {
        S[i] = S[i-1] + A[i];
    }
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 10, 300};
    vector<int> S;
    calcPrefixSum(arr, S);

    for (int val : arr) std::cout << val << " ";
    std::cout << "\n";
    for (int val : S) std::cout << val << " ";
    // S: 10, 30, 60, 100, 150
    std::cout << "\n";

    // 5부터 3까지의 합은 5에서 2까지의 합을 뺀 것과 같다
    // 1, 2, 3, 4, 5
    // 1, 3, 6, 10, 15
    // 5+4+3 = 12
    // s5 = 15, s2 = 3
    // s5 - s2 = 12
    // 어떤 정적인 배열에 대해 미리 계산해두면 굉장히 빠르게 합을 전달해줄 수 있다
    int range_sum = S[5] - S[2];
    cout << range_sum << endl;

    return 0;
}

