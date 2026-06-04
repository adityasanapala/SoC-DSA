#include<iostream>
using namespace std;
int main(){
    string x;
    cin>>x;
    int count=1;
    int pcount=0;
    for (int i=1;i < x.size();i++){
        if(x[i]==x[i-1]){count++;}
        else{
        if (count>pcount)
        {pcount=count;
        count=1;}
        else{count=1;}
        }
    }
     if (count>pcount)
        {pcount=count;
        count=1;}
    cout<<pcount<<endl;

    return 0;
}
