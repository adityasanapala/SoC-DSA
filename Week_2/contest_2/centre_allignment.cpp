#include <bits/stdc++.h>
using namespace std;   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<string> v;
    long long size = 0;
    while(getline(cin,s)){ 
        v.push_back(s);
        size = max(size, (long long)s.length());
    }
    for(int i = 0; i < v.size()+2; i++){
        if(i > 0 && i < v.size()+1){
            long long len = v[i-1].length();
            long long mid = (size - len)/2;
            if((size - len)%2 == 1){
                mid++;
            }
            v[i-1] = string(mid, ' ') + v[i-1] + string(size - mid - len, ' ');
        }

        for(int j = 0; j < size+2; j++){
            if(i == 0 || i == v.size()+1){
                cout << "*";
            }
            else if(j == 0 || j == size+1){
                cout << "*";
            }
            else 
                cout << v[i-1][j-1];
        }
        cout << "\n";
    }
    return 0;
}