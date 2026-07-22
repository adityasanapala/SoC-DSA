#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;

    vector<ll> a(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    vector<ll> leftSum(n+1);
    vector<ll> rightSum(n+2);

    leftSum[0]=0;
    for(int i=1;i<=n;i++){
        leftSum[i]=max(0LL,leftSum[i-1])+a[i];
    }

    rightSum[n+1]=0;
    for(int i=n;i>=1;i--){
        rightSum[i]=max(0LL,rightSum[i+1])+a[i];
    }

    vector<int> leftGreater(n+1),rightGreater(n+1);

    stack<int> st;

    for(int i=1;i<=n;i++){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }

        if(st.empty()){
            leftGreater[i]=0;
        }
        else{
            leftGreater[i]=st.top();
        }

        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    for(int i=n;i>=1;i--){
        while(!st.empty() && a[st.top()]<a[i]){
            st.pop();
        }

        if(st.empty()){
            rightGreater[i]=n+1;
        }
        else{
            rightGreater[i]=st.top();
        }

        st.push(i);
    }

    ll answer=0;

    for(int i=1;i<=n;i++){
        ll left=max(0LL,leftSum[i-1]);
        ll right=max(0LL,rightSum[i+1]);

        answer=max(answer,left+right);
    }

    cout<<answer<<endl;

    return 0;
}