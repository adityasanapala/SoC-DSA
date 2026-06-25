#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n>>x;
    long long a[n],b[n];
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);

    for (int i = 0; i < n - 2; i++) {

        int l = i + 1;
        int r = n - 1;

        while (l < r) {

            long long sum = a[i] + a[l] + a[r];

            if (sum == x) {

                int p = -1, q = -1, s = -1;

                for (int j = 0; j < n; j++) {

                    if (b[j] == a[i] && p == -1)
                        p = j;

                    else if (b[j] == a[l] && q == -1)
                        q = j;

                    else if (b[j] == a[r] && s == -1)
                        s = j;
                }

                cout << p + 1 << " "
                     << q + 1 << " "
                     << s + 1 << '\n';

                return 0;
            }

            if (sum < x)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}