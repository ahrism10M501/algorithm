#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<string, pair<int, int>> a,
            pair<string, pair<int, int>> b) {
                if(a.second.first == b.second.first) {
                    return a.second.second > b.second.second;
                } else {
                    return a.second.first > b.second.first;
                }
            }

int main(void) {
    vector<pair<string, pair<int, int>>> v;
    v.push_back(pair<string, pair<int, int>>("LEE", pair<int, int>(90, 20031234)));
    v.push_back(pair<string, pair<int, int>>("PARK", pair<int, int>(75, 19961222)));
    v.push_back(pair<string, pair<int, int>>("WANG", pair<int, int>(67, 19930612)));
    v.push_back(pair<string, pair<int, int>>("KIM", pair<int, int>(75, 1991091)));
    v.push_back(pair<string, pair<int, int>>("OH", pair<int, int>(67, 20050312)));

    sort(v.begin(), v.end(), compare);
    for(int i=0; i< v.size(); i++) {
        cout << v[i].first << ' ';
    }
    return 200;
}