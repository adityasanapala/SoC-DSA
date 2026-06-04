#include<iostream>
using namespace std;

int main(){
    long n;
    cin>>n;
    cout<<n<<" ";
    for (int i = 0;n>1; i++)
    {   if (n%2==0)
    {       n/=2;
            cout<<n<<" ";
        /* code */
    }
        else
        {   n=3*n;
            n+=1;
            cout<<n<<" ";
            /* code */
        }

        /* code */
    }

return 0;
}
