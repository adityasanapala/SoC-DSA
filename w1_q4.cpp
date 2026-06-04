#include<iostream>
using namespace std;
int lkns(long long int a){
   long long int i=a;
    long long int j=a;
    int s=9;
    int l=0;
    for (; i >0; )
    {
        if (i%10>l)
        {
            l=i%10;
            i/=10;
        }else i/=10;
        
    }
     for (; j >0; )
    {
        if (j%10<s)
        {
            s=j%10;
            j/=10;
        }else j/=10;
        
    }
    return (l-s);
}
int main(){
    int n;
    cin>>n;
    int lks[n]={};
    long long int lky[n];
    long long int lr[n];
    long long int ur[n];
    for (int i = 0; i < n; i++)
    {
        cin>>lr[i]>>ur[i];
    }
    for ( int i = 0; i < n; i++)
    {
        for (long long int  j = lr[i]; j <= ur[i]; j++)
        {
            if (lkns(j)>=lks[i])
            {
                lky[i]=j;
                lks[i]=lkns(j);
            }
            if (lkns(j)==9)
            {
                lky[i]=j;
                break;
            }
            
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<lky[i]<<endl;
    }
       return 0;
}