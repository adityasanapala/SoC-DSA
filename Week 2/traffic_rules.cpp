#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;

    double ans;

    // CASE 1 : w >= v

    if (w >= v) {

        double need = v * v / (2.0* a);   // distance to accel to v and decel back to 0

        if (l >= need) {
            ans = v / a + (l - need) / v;
        }
        else {
            ans = sqrt(2.0*l / a);
        }
    }

    // CASE 2 : w < v

    else {

        // ---------- Before the sign ----------

        double x = sqrt((2.0 * a * d + w * w) / 2.0);

        double T1;

        if (x <= v) {

            // 0 -> x -> w
            T1 = (2.0 * x - w) / a;
        }
        else {

            // 0 -> v -> cruise -> w

            double s_acc = v * v / (2.0 * a);
            double s_dec = (v * v - w * w) / (2.0 * a);

            double s_cruise = d - s_acc - s_dec;

            T1 = v / a + s_cruise / v + (v - w) / a;
        }

        // ---------- After the sign ----------

        double L = l - d;

        double s = (v * v - w * w) / (2.0 * a);

        double T2;

        if (L < s) {

            double y = sqrt(w * w + 2.0 * a * L);

            T2 = (y - w) / a;
        }
        else {

            T2 = (v - w) / a + (L - s) / v;
        }

        ans = T1 + T2;
    }
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}