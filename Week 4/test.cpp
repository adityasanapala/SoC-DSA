#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkin(string const& a, string const& b, int l1, int l2){
    //checking if b is in a
    //let l1 >= l2
    int p1 = 0;
    int p2 = 0;
    while(p1 < l1 - l2 + 1 && p2 < l2){
        if(a[p1] == b[p2]){
            p1++;
            p2++;
        }
        else{
            p1++;
        }
    }
    if(p2 >= l2 || p1 >= l1 - l2 + 1){
        return false;
    }
    return true;
}
bool checkinright(string const& a, string const& b, int l1, int l2){
    for(int i = 0; i < l2; i++){
        if(a[l1 - l2 + i] != b[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //string s;
    //getline(cin, s);
    // while (cin >> x){
    //     //code
    // }

    string s[3];
    for(int i = 0; i < 3; i++){
        cin >> s[i];
    }

    string ans;

    //start with longest string as ans
    
    int l = max({s[0].length(), s[1].length(), s[2].length()});
    
    for(int i = 0; i < 3; i++){
        if(s[i].length() == l){
            ans = s[i];
        }
    }

    

    for(int i = 0; i < 3; i++){
        string toAdd = "";
        if(!checkin(ans, s[i], l, s[i].length())){
            while(s[i].length() > 0){
                toAdd = s[i][s[i].length() - 1] + toAdd;
                s[i].pop_back();
                if(checkinright(ans, s[i], l, s[i].length())){
                    ans += toAdd;
                }
            }
        }
    }

    cout << ans <<endl;
    cout << ans.length() <<endl;
    return 0;
}
