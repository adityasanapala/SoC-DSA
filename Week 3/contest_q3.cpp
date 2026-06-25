#include<iostream>
using namespace std;
int main(){
    long long N;
    cin>>N;
    long long root[9];
    for(int i=0;i<9;i++){
        root[i]=0;
    }
    for(int i=1;i<=N;i++){
        int r = i%9;
        root[r]++;
    }
    long long accepted=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int dr = (i * j) % 9;
            accepted = accepted + root[i]*root[j]*root[dr];
        }
    }
    long long correct = 0;
    for (long long A = 1; A <= N; A++) {
        correct = correct + N / A;
    }

    cout << accepted - correct << '\n';
    return 0;
}