#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin >> t;
for(int i=0;i<t;i++){
    long long l,r,luck=-1,max_l;
    cin >> l >> r;
    while(l<=r){
        long long max_num=0,min_num=9,templ,p;
        templ = l;
        while(templ>0){
        p = templ%10;
        if(p>max_num){
            max_num = p;
        }
        if(p<min_num){
            min_num = p;
        }
        if(luck<max_num-min_num){
            luck = max_num-min_num;
            max_l = l;
        }
        if(luck == 9){
            break;
        }
        templ = templ/10;
        }
        if(luck == 9){
            break;
        }
        l++;
    }
    cout << max_l<<"\n";
}
}