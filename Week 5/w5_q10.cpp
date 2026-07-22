#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

bool checkOdd(vector<ll> &a, int n, int k, ll x){
    int length = 0;

    for(int i=0;i<n;i++){
        if(length%2==0){
            if(a[i]<=x){
                length++;
            }
        }
        else{
            length++;
        }
    }

    return length>=k;
}

bool checkEven(vector<ll> &a, int n, int k, ll x){
    int length = 0;

    for(int i=0;i<n;i++){
        if(length%2==1){
            if(a[i]<=x){
                length++;
            }
        }
        else{
            length++;
        }
    }

    return length>=k;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll low=1;
    ll high=1000000000;
    ll answer=high;

    while(low<=high){
        ll mid=(low+high)/2;

        if(checkOdd(a,n,k,mid) || checkEven(a,n,k,mid)){
            answer=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<answer<<endl;

    return 0;
}