#include <bits/stdc++.h>
using namespace std;
 
int main () {
    string s; long long ans = 0; int count = 0;
    
    while (getline(cin , s)) {
        
        if (s[0] == '+')
        count++;
        
        else if (s[0] == '-')
        count--;
        
        else {
            
            size_t location = s.find(':');
            
            ans = ans + count * ( s.size() - location -1);
        } 
    }
    
    cout << ans;
}