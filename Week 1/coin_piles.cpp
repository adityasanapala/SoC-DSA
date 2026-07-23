#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b;
    if((a+b)%3==0 && 2*a>=b && 2*b >= a) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    }
}
//possible values of a and b seen observed for every a,b sum is 3m 
//but not all pairs whose sum is 3m wont satisfy the restriction max one no. can be double of other