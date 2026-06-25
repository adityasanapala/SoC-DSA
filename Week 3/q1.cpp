#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n],d[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>d[i];
    }
    sort(a,a+n);
    long ans=0;
    for(int i=0;i<n;i++){
        ans = ans + d[i]-(n-i)*a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
