#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;
    getline(cin, line);
    ll max_length = 0, count = 1;
    stack<int> s;
    s.push(-1);
    for(ll i = 0; i<line.length(); i++){
        if(line[i] == '('){
            s.push(i);
        }
        else if(line[i] == ')'){
            s.pop();
            if(!s.empty()){
                ll current_length = i - s.top();
                if(current_length > max_length){
                    max_length = current_length;
                    count = 1;
                }
                else if(current_length == max_length && current_length > 0){
                    count++;
                }
            }
            else {
                s.push(i);
            }
        }
    }
    cout << max_length << " " << count << endl;
}