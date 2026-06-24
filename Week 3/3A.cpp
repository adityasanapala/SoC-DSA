#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p1, p2, p3, t1, t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    vector<pair<int,int>> interval;
    for(int i = 0; i < n; i++){
        int st, ed;
        cin>>st>>ed;
        interval.push_back({st,ed});
    }
    int power = 0;
    for(int i = 0; i < interval.size(); i++){
        power += ((interval[i].second - interval[i].first)*(p1));
    }
    for(int i = 1; i < interval.size(); i++){
        int timediff = (interval[i].first - interval[i-1].second);
        if(timediff <= t1){
            power += ((timediff)*(p1));
        }
        else if(timediff > t1 && timediff <= (t1+t2)){
            power += ((t1*p1) + ((timediff-t1)*p2));
        }
        else{
            power += ((t1*p1) + (t2*p2) + ((timediff - (t1+t2))*p3));
        } 
    }
    cout<<power<<endl;
    return 0;
}