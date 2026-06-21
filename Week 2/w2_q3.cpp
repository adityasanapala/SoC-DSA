#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,y,p=-1,q=-1,s=-1,k,m,o;
    bool found=false;;
    cin>>n>>x;
    vector<ll>a;
    for(int i=0;i<n;i++){
        cin>>y;
        a.push_back(y);
    }
    vector<ll>b=a;
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        y=x-b[i]; 

        ll l=i+1,r=n-1;
        while(l<r){
            if((b[l]+b[r])>y)r--;
            else if((b[l]+b[r])<y)l++;
            else{
                p=b[l];
                q=b[r];
                s=b[i];
                found =true;
                break;
            }
        }
        if(found==true)break;
    }
    if(p==-1||q==-1)cout<<"IMPOSSIBLE\n";
    else{
        for(int i=0;i<n;i++){
            if(a[i]==p){k=i; break;}
            }
        for(int i=0;i<n;i++){
            if(a[i]==q&&k!=i){m=i; break;}
        }
        for(int i=0;i<n;i++){
            if(a[i]==s&&k!=i&&m!=i){o=i; break;}
        }
        cout<<k+1<<" "<<m+1<<" "<<o+1;
    }
}
//done
