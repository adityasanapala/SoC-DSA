#include<iostream>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    cout<<n<<" ";
    for (int i=0 ; n>1; i++)

    {
        if (n%2==0)
        {
          n/=2;
          cout<<n<<" ";
        }
        else
        {
          n=(n*3)+1;
          cout<<n<<" ";
        }
        
    }
    
    return 0;
}