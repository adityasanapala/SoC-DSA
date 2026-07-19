#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    
    int st[n]; 
    int ml[n];
    
    int top = 0; 

    for (int i = 0; i < n; ++i) {
        ml[i] = 0;
        
        if (s[i] == '(') {
            st[top++] = i;
        } else {
            if (top > 0) {
                int qwer = st[--top]; 
                
                int len = i - qwer + 1;
                
                if (qwer > 0) {
                    len += ml[qwer - 1];
                }
                
                ml[i] = len;
            }
        }
    }

    int max = 0;
    int count = 1; 

    for (int i = 0; i < n; ++i) {
        if (ml[i] > max) {
            max = ml[i];
            count = 1;
        } else if (ml[i] == max && max > 0) {
            count++;
        }
    }

    cout << max << " " << count << "\n";

    return 0;
}