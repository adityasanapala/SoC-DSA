#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> pos(n + 1);
        for(int i=1;i<=n;i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        int l = (n + 1)/2;
        int r = (n + 2)/2;
        int ans = 0;

        while (l>0 && r<n+1 && (l==r||(pos[l]<pos[r] && pos[l]<pos[l+1] && pos[r-1]<pos[r]))) {
            l--;
            r++;
        }
        cout << (n-(r-l)+1)/2 << "\n";
    }
}
