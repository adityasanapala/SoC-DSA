#include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>
  #define pb push_back
  using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v.pb({arr[i],i+1});
    }
    sort(v.begin(),v.end());


    for(int i=0;i<n-2;i++){
        int k= x-v[i].first;
       int l=i+1;   //left window
       int r=n-1;   //right window

       while(v[l].first+v[(r)/2].first>k ){  //reducing time complexity
        r=(l+r)/2;
        if(l>=r){cout<<"IMPOSSIBLE";           //if r becomes equal l, then no solution
        return 0;}}
       if(v[(l+r)/2].first+v[n-1].first<k)l=(l+r)/2;   //reducing more time complexity but not much
       while(l!=r){
        if(v[l].first+v[r].first==k){
            cout<<v[i].second<<" "<<v[l].second<<" "<< v[r].second;
            return 0;
        }
        if(v[l].first+v[r].first>k){
            r--;
        }else{l++;}                 // increaing and decreasing the window
       }


    }
    cout<<"IMPOSSIBLE";










}
