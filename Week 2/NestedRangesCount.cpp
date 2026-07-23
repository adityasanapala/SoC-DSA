#include <bits/stdc++.h>
using namespace std;

struct Range{
    int l,r,id;
};

struct BIT{
    int n;
    vector<int> bit;

    BIT(int n){
        this->n=n;
        bit.assign(n+1,0);
    }

    void update(int idx,int val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }

    int query(int idx){
        int sum=0;
        while(idx){
            sum+=bit[idx];
            idx-=idx&-idx;
        }
        return sum;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<Range> a(n);
    vector<int> vals;

    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        vals.push_back(a[i].r);
    }

    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    auto get=[&](int x){
        return lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
    };

    sort(a.begin(),a.end(),[](Range &x,Range &y){
        if(x.l==y.l)
            return x.r>y.r;
        return x.l<y.l;
    });

    vector<int> contains(n),contained(n);

    BIT bit(vals.size());

    for(int i=n-1;i>=0;i--){
        int pos=get(a[i].r);
        contains[a[i].id]=bit.query(pos);
        bit.update(pos,1);
    }

    BIT bit2(vals.size());

    for(int i=0;i<n;i++){
        int pos=get(a[i].r);
        contained[a[i].id]=i-bit2.query(pos-1);
        bit2.update(pos,1);
    }

    for(int x:contains)
        cout<<x<<" ";
    cout<<"\n";

    for(int x:contained)
        cout<<x<<" ";
}