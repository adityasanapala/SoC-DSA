#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int luck = l;
        int best = -1;

        int range = min(r, l + 100);

        for (int i=l;i<=range; i++) 
        {
            int x = i;
            int minm = 9, maxm = 0;

            while (x) {
                int d = x % 10;
                minm = min(minm, d);
                maxm = max(maxm, d);
                x /= 10;
            }

            int diff = maxm-minm;

            if (diff>best) 
            {
                best=diff;
                luck=i;
            }

            if (best==9)
                break;
        }

        cout << luck << '\n';
    }
}

