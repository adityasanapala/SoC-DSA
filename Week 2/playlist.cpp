#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
set<int> wind;
int n,lefti=0,righti=0,maxl=0;
cin >> n;
vector<int> playlist(n);
for(int i=0;i<n;i++){
    cin>>playlist[i];
}
for(righti=0;righti<n;righti++){
    int current = playlist[righti];
    while(wind.count(current)>0){
        wind.erase(playlist[lefti]);
        lefti++;
    }
    wind.insert(current);
    maxl = max(maxl,righti-lefti+1);
}
cout << maxl;
}