#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int k = 1; k <= n; k++) {

        int start = n - k;
        long long money = 0;

        for (int i = start; i < n; i++) {

            if (money >= a[i])
                money -= a[i];
            else
                money += a[i];

        }

        cout << money << " ";
    }

    cout << '\n';
}