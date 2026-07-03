#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){ 
    int n,x;
    cin>>n;
    vector<int> v(n+1);
    v[0]=0;
    for(int i=1 ;i < n+1; i++){
        cin>>x;
        v[x]=i;
    }
    int r = (n+1)/2;
    if(v[r]>v[n+1-r]) {
        cout << r << endl;
        continue;
    }
    //r  to n+1-r values are in correct order
    while(r>1 && v[r-1]<v[r] && v[n+1-r]<v[n+2-r]){
        r--;
    }
    cout<< r-1 <<"\n";
    }
}