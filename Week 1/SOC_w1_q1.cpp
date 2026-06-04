#include <iostream>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long x;
    long long int oldsum=0;
    for (int i = 0; i <n-1; i++)
    {   cin>>x; 
        oldsum+=x;
        /* code */
    }
    long long int sum = (n*(n+1))/2;

    cout<<(sum-oldsum)<<endl;

    return 0;
}
