#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i = 0; i < n ; i++){
        cin>>a[i];
    }
    long long ans = -1;
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++){
            long long val = a[i-1] - 1;
            long long cand_sum = a[j];
            long long cand_coins = 1;
            for(int k = i; k <= j; k++){
                long long count = val/a[k];
                val %= a[k];
                cand_sum += count * a[k];
                cand_coins += count;
            }
            long long greedy_val = cand_sum;
            long long greedy_coins = 0;
            for(int k = 0; k < n; k++){
                greedy_coins += greedy_val / a[k];
                greedy_val %= a[k];
            }
            if(greedy_coins > cand_coins){
                if(ans == -1 || cand_sum < ans){
                    ans = cand_sum;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}