#include <iostream>

using namespace std;

int cnt[1000005];

int main() {   
    int n, k;
    cin >> n >> k;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int l = 0, uniq = 0;
    int max = 0;
    int ans_l = 1, ans_r = 1;
    
    for (int r = 0; r < n; r++) {
        if (cnt[a[r]] == 0) {
            uniq++;
        }
        cnt[a[r]]++;
        
        while (uniq > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                uniq--;
            }
            l++;
        }
        
        if (r - l + 1 > max) {
            max = r - l + 1;
            ans_l = l + 1;
            ans_r = r + 1;
        }
    }
    
    cout << ans_l << " " << ans_r << "\n";
    
    return 0;
}