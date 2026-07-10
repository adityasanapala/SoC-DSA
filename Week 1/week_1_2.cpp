#include<iostream>

using namespace std;

int main() {
    string c;
    cin>>c;
    int n=c.size();
    int max=1;
    int current=1;
    for (int i=1; i<n; i++) {
        if (c[i]==c[i-1]) {
            current+=1;
        } else {
            current=1;
        }
        if (current>max) {
            max=current;
        }
    }
    cout<<max<<endl;
    return 0;
}