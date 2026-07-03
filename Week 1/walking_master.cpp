#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int x=a-c+d-b,y=d-b;
        if(x>=0 && y>=0){
            cout<<x+y<<"\n";
        }
        else cout<<-1<<"\n";
    }
}