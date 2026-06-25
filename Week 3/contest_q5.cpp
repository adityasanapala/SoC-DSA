#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
void greedy(ll x,int n, ll a[], ll count[]){
    for (int i = 0; i < n; i++) {
        count[i] = x / a[i];
        x %= a[i];
    }
}
ll countCoins(ll count[], int n) {
    ll total = 0;

    for (int i = 0; i < n; i++)
        total += count[i];

    return total;
}
int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll count[n],m[n],countm[n];
    ll ans=-1;
    for(int i=0;i<n;i++){
        greedy(a[i - 1] - 1, n, a, count);
        for(int j=1;j<n;j++){
            for(int k=0;k<n;k++){
                m[k]=count[k];
            }
            m[j]++;
            for (int k = j + 1; k < n; k++)
                m[k] = 0;
            ll value = 0;
            for(int k=0;k<n;k++){
                value+= m[k]*a[k];
            }
            greedy(value,n,a,countm);
            if (countCoins(countm, n) > countCoins(m, n)) {
                if (ans == -1 || value < ans)
                    ans = value;
            }
        }
    }
    cout<<ans<<"\n";
}