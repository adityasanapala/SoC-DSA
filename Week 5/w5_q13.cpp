#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int max_score = 0;
    for(int v = 0; v <= 30; v++){
        int current_kadane = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > v){
                current_kadane = 0;
            }
            else{
                current_kadane += a[i];
                max_score = max(max_score, current_kadane - v);
                if(current_kadane < 0){
                    current_kadane = 0;
                }
            }
        }
    }
    cout<<max_score<<endl;
    return 0;
}