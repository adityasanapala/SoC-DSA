#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    int cur = 0;
    int traffic = 0;

    while(getline(cin, a)){
        if(a[0] == '+'){
            cur++;
        }

        else if(a[0] == '-'){
            cur--;
        }

        else{
            int l = 0;
            bool colon = false;

            for(int i=0; i<a.length();i++){
                if(colon){
                    l++;
                }

                if(a[i] == ':'){
                    colon = true;
                }
            }
            traffic += l*cur;
        }
    }

    cout << traffic;

    return 0;
}