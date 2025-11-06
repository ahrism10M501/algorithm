#include <iostream>
#include <algorithm>

using namespace std;

int n;
string a[50];

int getSum(string a) {
    int length = a.length(), sum = 0;
    for(int i = 0; i< length; i++) {
        // 숫자인 경우에만 연산
        if(a[i] - '0' <= 9 && a[i] - '0' >= 0) {
            sum += a[i] -'0';
        }
    }
    return sum;
}

bool compare(string a, string b){
    // 길이가 짧은걸 앞에다 위치하겠다
    if(a.length() < b.length()) {
        return 1;
    } else if (a.length() > b.length()){
        return 0;
    }
    else {
        int aSum = getSum(a);
        int bSum = getSum(b);
        if(aSum != bSum) {
            return aSum < bSum;
        } else {
            return a < b;
        }
    }
}

int main(void) {
    cin >> n;
    for (int i=0; i< n; i++) {
        cin >> a[i]; 
    }
    sort(a, a+n, compare);
    for(int i=0; i<n; i++) {
        if ( i>0 && a[i]== a[i-1]) {
            continue;
        }
        else {
            cout << a[i] << endl;
        }
    }
    return 0;
}