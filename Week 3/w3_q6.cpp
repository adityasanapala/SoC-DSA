#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

int main(){
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> v(N + 1);
    v[0].first = 0;
    v[0].second = 0;
    for(int i = 1; i < N + 1; i++){
        cin >> v[i].first >> v[i].second;
    }
}