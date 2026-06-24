#include<bits/stdc++.h>
using namespace std;

struct Fenwick{
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n+1, 0){}
    void add(int indx, int val){
        for(;indx <= n; indx += indx & -indx) bit[indx] += val;
    }
    int sum(int indx){
        int r = 0;
        for(; indx > 0; indx -= indx & -indx) r += bit[indx];
        return r;
    }
    int rangesum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

int main(){
    int n, q;
    cin>>n>>q;
    Fenwick rb(n), cb(n);
    vector<int> rc(n+1,0);
    vector<int> cc(n+1,0);
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int x,y;
            cin>>x>>y;
            rc[x]++;
            if(rc[x] == 1) rb.add(x,1);
            cc[y]++;
            if(cc[y] == 1) cb.add(y,1);
        }
        else if(t == 2){
            int x,y;
            cin>>x>>y;
            rc[x]--;
            if(rc[x] == 0) rb.add(x,-1);
            cc[y]--;
            if(cc[y] == 0) cb.add(y,-1);
        }
        else{
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            bool rowscovered = rb.rangesum(x1,x2) == (x2-x1+1);
            bool colscovered = cb.rangesum(y1,y2) == (y2-y1+1);
            cout<<(rowscovered || colscovered ? "Yes" : "No")<<'\n';
        }
    }
    return 0;
}