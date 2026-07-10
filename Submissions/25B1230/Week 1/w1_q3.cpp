#include <iostream>
using namespace std;

int main(){
    long long t,n,k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin>> n >> k;
        if(n%2 ==0){
            cout << "YES" << endl;
        }
        else if(k%2 ==0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}