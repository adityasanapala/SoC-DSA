#include<iostream>
#include<string>
using namespace std;

string lines[1000];

int main(){
    string a;
    int max = 0;
    int i = 0;

    while(getline(cin, a)){
        if(a.length() > max){
            max = a.length();
        }

        lines[i] = a;

        i++;
    }

    for (int i = 0; i < max + 2; i++) {
        cout << "*";
    }
    cout << endl;

    bool left1 = true;

    for(int j=0; j<i; j++){
        string cur = lines[j];
        int spaces = max - cur.length();

        int left = 0;
        int right = 0;

        if(spaces % 2 == 0){
            left = spaces/2;
            right = spaces/2;
        }
        else{
            if(left1){
                left = spaces/2;
                right = spaces/2 + 1;
            }
            else{
                left = spaces/2 + 1;
                right = spaces/2;
            }
            left1 = !left1;
        }

        cout << '*';

        for(int k=0; k<left; k++){
            cout << " ";
        }

        cout << cur;

        for(int k=0; k<right; k++){
            cout << " ";
        }

        cout << '*' << endl;
    }

    for (int i = 0; i < max + 2; i++) {
        cout << "*";
    }
    
    return 0;
}