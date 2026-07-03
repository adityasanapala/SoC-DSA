#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n,int initial,int destination,int helper){
    if(n==0) return;

    hanoi(n-1,initial,helper,destination);
    cout<<initial<<" "<<destination<<"\n";
    hanoi(n-1,helper,destination,initial);
}

int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<"\n";
    hanoi(n,1,3,2);
}