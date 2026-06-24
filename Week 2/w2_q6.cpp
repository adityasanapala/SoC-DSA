#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> result;
    int ans = 0;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        vector<int> pos(x+1);
        for(int j = 1; j <= x; j++){
            int y;
            cin>>y;
            pos[y] = j;
        }
     int l = (x+1)/2;
     int r = (x+2)/2;
     if(l == r || pos[l] < pos[r]){
        while(l > 1 && r < x && pos[l-1] < pos[l] && pos[r] < pos[r+1]){
            l--;
            r++;
        }
        cout<<l-1<<endl;
     }else{
        cout<<l<<endl;
     }
      
    }
    return 0;
}