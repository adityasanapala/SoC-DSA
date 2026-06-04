#include<iostream>
using namespace std;
int main(){
    int p;
    cin>>p;
    long long int n[p];
    long long int k[p];
    long long int d;
    for (long long int i = 0; i < p; i++)
    {
        cin>>n[i]>>k[i];
    }
    for (long long int i = 0; i < p; i++)
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