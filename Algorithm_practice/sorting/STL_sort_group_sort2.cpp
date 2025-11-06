#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(90, "LEE"));
    v.push_back(pair<int, string>(60, "PARK"));
    v.push_back(pair<int, string>(50, "MYENG"));
    v.push_back(pair<int, string>(70, "KIM"));
    v.push_back(pair<int, string>(40, "CHOI"));

    sort(v.begin(), v.end());

    for(int i=0; i< v.size(); i++){
        cout << v[i].second << ' ';
    }
}