#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct task{
    ll time;
    ll deadline;
 
    task() = default;
    task(ll t, ll d){
        time = t;
        deadline = d;
    }
};
 
//sort according to least time taking task first, and if time is same, lower deadline first
bool sorttask(const task &a, const task &b){
    if(a.time == b.time){
        return a.deadline < b.deadline;
    }
    return a.time < b.time;
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
 
    ll n;
    cin >> n;
 
    vector<task> tasks(n);
 
    for(ll i = 0; i < n; i++){
        cin >> tasks[i].time >> tasks[i].deadline;
    }
 
    sort(tasks.begin(), tasks.end(), sorttask);
 
    ll timecount = 0;
    ll reward = 0;
 
    for(ll i = 0; i < n; i++){
        auto &current = tasks[i];
        timecount += current.time;
        reward += current.deadline - timecount;
    }
 
    cout << reward <<endl;
    return 0;
}