#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    long long int n[x];
    long long int k[x];
    for (long long int i = 0; i < x; i++)
    {
        cin>>n[i]>>k[i];
    }
    for (long long int i = 0; i < x; i++)
    {
        if (k[i]<n[i])
        {
          if (k[i]==1){cout<<"YES"<<endl;}
        else if (k[i]%2==0)
        {
            if (n[i]%2==0)
            {
                {cout<<"YES"<<endl;}
            }else { cout<<"NO"<<endl;}
        }else {
            cout<<"YES"<<endl;
        }
    }else if (k[i]>n[i])
    {
          if (n[i]%2==0)
            {
                {cout<<"YES"<<endl;}
            }else { cout<<"NO"<<endl;}
    }else {cout<<"YES"<<endl;}

}
    return 0;
}
