#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int overlap(const string &a, const string &b){
    string s = b + "." + a;

    vector<int> pi(s.size());

    for(int i=1;i<s.size();i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }

    return min((int)b.size(), pi.back());
}

string merge(string &a, string &b){
    if(a.find(b) != string::npos)
        return a;

    int x = overlap(a,b);
    return a + b.substr(x);
}

int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    string a,b,c;

    a=merge(s1,s2);
    b=merge(a,s3);

    a=merge(s2,s3);
    c=merge(a,s1);

    if(b.size()>c.size())b=c;

    a=merge(s3,s1);
    c=merge(a,s2);

    if(b.size()>c.size())b=c;
    
    a=merge(s1,s3);
    c=merge(a,s2);

    if(b.size()>c.size())b=c;

    a=merge(s3,s2);
    c=merge(a,s1);

    if(b.size()>c.size())b=c;

    a=merge(s2,s1);
    c=merge(a,s3);

    if(b.size()>c.size())b=c;

    cout<<b.size()<<endl;

}