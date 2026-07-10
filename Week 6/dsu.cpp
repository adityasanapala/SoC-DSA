#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class dsu{
    public:
    int n;
    vector<int> parent, rank;
    dsu(int n){
        this -> n = n;

        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int n){
        int p = parent[n];
        if(p == n) return p;
        return parent[n] = find(parent[n]); //path compression
    }

    void dsunion(int u, int v){ //union is a cpp keyword
        int a = find(u);
        int b = find(v);

        if(a == b) return;
        if(rank[a] == rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else if (rank[a] > rank[b]){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }
    }

    void getInfo(){
        for(int i = 0; i < n; i++){
            cout << parent[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

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

    // int t;
    // cin >> t;
    // while(t--){
    //     //code
    // }

    dsu dsu(6);
    dsu.dsunion(0,2) ;
    cout << dsu.find(2) <<endl;
    dsu.dsunion(1,3) ;
    dsu.dsunion(2,5) ;
    dsu.dsunion(0,3) ;
    cout << dsu.find(2) << endl;
    dsu.dsunion(0,4);
    dsu.getInfo();
    return 0;
}
