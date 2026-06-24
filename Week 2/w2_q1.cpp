#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //string s;
    //getline(cin, s);
    // while (cin >> x){
    //     //code
    // }

    int n;
    cin >> n;

    vector<ll> ids(n);

    for(int i = 0; i < n; i++){
        cin >> ids[i];
    }

    set<int> s;
    int longest = 0;
    int l = 0;

    for(int r = 0; r < n; r++){
        //check if the element is in the set already
        while(s.count(ids[r])){
            //keep removing elements from the left as long as there is no element the same as ids[r]
            s.erase(ids[l]);
            l++;
        }
        //inserts an element which is not in the set as we removed it in the previous step
        s.insert(ids[r]);
        longest = max(longest, r - l + 1);
    }

    cout << longest <<endl;

    return 0;
}