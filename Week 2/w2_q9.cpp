#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


struct Range{
    int start;
    int end;
    int idx;

    Range() = default;

    Range(int s, int e, int i){
        start = s;
        end = e;
        idx = i;
    }
};

//sort ranges by ascending order of start and descending order of end
bool sortRange(const Range &a,const Range &b){
    if(a.start == b.start){
        return b.end < a.end;
    }
    return a.start < b.start;
}

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
    vector<Range> ranges(n);
    ordered_multiset<int> ends;

    for(int i = 0; i < n; i++){
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].idx = i;
    }

    sort(ranges.begin(), ranges.end(), sortRange);

    //how many of the other ranges are inside it
    int inside[n];
    for(int i = 0; i < n; i++){
        const auto& current = ranges[i];

        int lb = ends.order_of_key(current.end);
        inside[current.idx] = ends.size() - lb;
        ends.insert(current.end);
    }

    ends.clear();

    //how many of the other ranges it is inside
    int outside[n];
    for(int i = n - 1; i >= 0; i--){
        const auto& current = ranges[i];

        int ub = ends.order_of_key(current.end + 1);
        outside[current.idx] = ub;
        ends.insert(current.end);
    }

    for(int i = 0; i < n; i++){
        cout <<outside[i];
        if(i < n - 1) cout << " ";
    }
    cout <<endl;

    for(int i = 0; i < n; i++){
        cout<< inside[i];
        if(i < n - 1) cout << " ";

    }

    cout << endl;

    return 0;
}