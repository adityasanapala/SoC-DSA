#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t>0){
        string s;
        cin>>s;
        if(s[0]!='1')cout<<"NO";
        else if(s[s.size() - 1]=='9')cout<<"NO";
        else{
            ll n=s.size()-1;
            ll large=1;
            for(int i=1;i<n;i++){
                if(s[i]=='0'){
                    cout<<"NO";
                    large=0;
                    break;
                }
            }
            if(large==1){
                cout<<"YES";
            }

       }
       cout<<endl;
        t--;
    }
}