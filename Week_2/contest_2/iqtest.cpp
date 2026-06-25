#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count0 = 0, count1 = 0;
    int index0 = 0, index1 = 0;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        if(p % 2 == 0){
            count0++;
            index0 = i + 1;
        }
        else{
            count1++;
            index1 = i + 1;
        }
    }
    if(count0 == 1){
        cout << index0;
    }
    else if(count1 == 1){
        cout << index1;
    }
    return 0;
}