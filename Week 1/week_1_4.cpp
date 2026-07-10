#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int l,r;
        cin>>l>>r;
        int d=0;
        int max_d=0;
        int ans=l;
        for (int j=l; j<=min(r,l+100); j++) {
            int max=0;
            int min=9;
            int x=j;
            while (x>0) {
                int digit=x%10;
                if (digit>max) max=digit;
                if (digit<min) min=digit;
                x/=10;
            }
            d=abs(max-min);
            if (d>max_d) {
                max_d=d;
                ans=j;
            }
        }
        cout<<ans<<endl;
    }
}