#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int i=0;
    while(i<n){
        if(n-i == 3){
            cout << s[i] << s[i+1] << s[i+2];
            break;
        }

        if(n-i == 2){
            cout << s[i] << s[i+1];
            break;
        }

        else{
            cout << s[i] << s[i+1] << '-';
            i += 2;
        }
    }

    cout << endl;

    return 0;
}