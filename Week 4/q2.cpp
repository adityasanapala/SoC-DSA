#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    int i=0;
    if(n%3==0){
        while (i < n) {
            cout << s.substr(i, 3);
            i += 3;

            if (i < n)
                cout << '-';
        }
    }
    else if(n%3==1){
        while (n - i > 4) {
            cout << s.substr(i, 3) << '-';
            i += 3;
        }

        cout << s.substr(i, 2) << '-'
             << s.substr(i + 2, 2);
    }
    else{
        while (n - i > 2) {
            cout << s.substr(i, 3) << '-';
            i += 3;
        }

        cout << s.substr(i, 2);
    }
    cout<<"\n";
    return 0;
}