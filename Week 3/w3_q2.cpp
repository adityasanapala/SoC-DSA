  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>

  using namespace std;




bool check(long long arr[], long long t, long long n, long long p) {
    long long total_products = 0;
    for(long long i = 0; i < n; i++) {
        total_products += t / arr[i];


        if (total_products >= p) {
            return true;
        }
    }
    return total_products >= p;
}

int main() {

    long long n, p;
    if (!(cin >> n >> p)) return 0;


    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

              // Binary search directly on the TIME
    long long l = 0;
    long long r = 1e18; // Max possible time (10^9 products * 10^9 max machine time)
    long long ans = r;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (check(arr.data(), mid, n, p)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
