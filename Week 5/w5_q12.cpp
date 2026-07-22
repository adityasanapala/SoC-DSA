#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;

    while(t--){
        int k;
        cin>>k;

        vector<ll> cnt(k);
        ll total=0;

        for(int i=0;i<k;i++){
            cin>>cnt[i];
            total+=cnt[i];
        }

        vector<ll> fib;
        fib.push_back(1);
        fib.push_back(1);

        ll sum=2;

        while(sum<total){
            ll next=fib[fib.size()-1]+fib[fib.size()-2];
            fib.push_back(next);
            sum+=next;
        }

        if(sum!=total){
            cout<<"NO"<<endl;
            continue;
        }

        sort(cnt.begin(),cnt.end());
        sort(fib.begin(),fib.end());

        bool ok=true;

        int i=cnt.size()-1;
        int j=fib.size()-1;

        while(j>=2){
            if(i<0 || cnt[i]!=fib[j]){
                ok=false;
                break;
            }
            i--;
            j--;
        }

        if(ok){
            vector<ll> rem;
            while(i>=0){
                rem.push_back(cnt[i]);
                i--;
            }

            sort(rem.begin(),rem.end());

            if(rem.empty()){
                ok=false;
            }
            else{
                rem.back()-=2;
                if(rem.back()<0){
                    ok=false;
                }
                else{
                    sort(rem.begin(),rem.end());

                    int p=rem.size()-1;
                    while(j>=0){
                        if(p<0 || rem[p]!=fib[j]){
                            ok=false;
                            break;
                        }
                        p--;
                        j--;
                    }
                }
            }
        }

        if(ok){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}