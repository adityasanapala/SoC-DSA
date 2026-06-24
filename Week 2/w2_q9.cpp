#include<bits/stdc++.h>
using namespace std;

struct bit{
    vector<int> b;
    int n;
    bit(int n){
        this->n = n;
        b.assign(n+1, 0);
    }
    void update(int indx, int val){
        while(indx <= n){
            b[indx] += val;
            indx += indx & -indx;
        }
    }
    int query(int indx){
        int sum = 0;
        while(indx > 0){
            sum += b[indx];
            indx -= indx & -indx;
        }
        return sum;
    }
};

struct range{
    int l,r,indx;
};

int main(){
    int n;
    cin>>n;
    vector<range> ranges(n);
    vector<int> rights;
    for(int i = 0; i < n; i++){
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].indx = i;
        rights.push_back(ranges[i].r);
    }
    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());
    for(int i = 0; i < n; i++){
        ranges[i].r = lower_bound(rights.begin(), rights.end(), ranges[i].r) - rights.begin() + 1;
    }
    sort(ranges.begin(), ranges.end(),
    [](range a, range b){
        if(a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });
    vector<int> contains(n);
    vector<int> contained(n);

    int m = rights.size();
    bit b1(m);
    for(int i = n-1; i >= 0; i--){
        int r = ranges[i].r;
        contains[ranges[i].indx] = b1.query(r);
        b1.update(r,1);
    }
    bit b2(m);
    for(int i = 0; i < n; i++){
        int r = ranges[i].r;
        contained[ranges[i].indx] = b2.query(m) - b2.query(r-1);
        b2.update(r,1);
    }
    for(auto x : contains){
        cout<<x<<" ";
    }
    cout<<'\n';
    for(auto x : contained){
        cout<<x<<" ";
    }
    cout<<'\n';
    return 0;
}