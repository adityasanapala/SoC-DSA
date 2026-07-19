#include <iostream>

using namespace std;

int dr(int x) {    
    return ((x - 1) % 9) + 1;
}

int main() {
    long long N;
    cin >> N;

    long long qwer[10] = {0}; 
    
    for (int i = 1; i <= 9; i++) {
        qwer[i] = N / 9;
    }
    for (int i = 1; i <= N % 9; i++) {
        qwer[i]++;
    }

    long long pass = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int k = dr(i * j);
            pass += qwer[i] * qwer[j] * qwer[k];
        }
    }

    long long cor = 0;
    for (long long i = 1; i <= N; i++) {
        cor += N / i;
    }

    long long mistakes = pass - cor;
    cout << mistakes << endl;

    return 0;
}