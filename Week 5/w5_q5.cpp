#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        ll c;
        cin>>n>>c;

        vector<ll> s(n);

        ll answer=(c+1)*(c+2)/2;

        for(int i=0;i<n;i++){
            cin>>s[i];

            answer-=s[i]/2+1;
            answer-=c-s[i]+1;
        }

        int even=0;
        int odd=0;

        for(int i=0;i<n;i++){
            if(s[i]%2==0){
                answer+=even+1;
                even++;
            }
            else{
                answer+=odd+1;
                odd++;
            }
        }

        cout<<answer<<endl;
    }

    return 0;
}