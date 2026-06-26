#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N;
ll T, cnt, k[maxN];

// this is a function to check
bool check(ll t) {
    cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += t / k[i];
        if (cnt >= T) return true;
    }
    return false;
    // this checks if the no of machines produced are mmore than the tgt
    // if so then returns true
    // will be used to keep the track of minimum possible time
    // if for any given time the no. of machines produced is less then the target
    // it will return false
    // and then I will return the old answer
}

int main() {
    scanf("%d %lld", &N, &T);
    for (int i = 0; i < N; i++) scanf("%lld", &k[i]);
    ll lo = 0, hi = 1e18;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) { hi = mid - 1; }
        else { lo = mid + 1; }
    }
    // Also in binary search, We don't get to mid we get to mid+1 and mid-1
    // Also the cond is <= and not <
    // FunFact = I don't know Binary Search
    printf("%lld\n", lo);
}
