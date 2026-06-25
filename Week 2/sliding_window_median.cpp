#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> left, right;

    auto balance = [&]() {

        while (left.size() > right.size() + 1) {

            right.insert(*left.rbegin());

            auto it = left.end();
            it--;

            left.erase(it);
        }

        while (left.size() < right.size()) {

            left.insert(*right.begin());
            right.erase(right.begin());
        }
    };

    for (int i = 0; i < k; i++) {

        if (left.empty() || a[i] <= *left.rbegin())
            left.insert(a[i]);
        else
            right.insert(a[i]);

        balance();
    }

    cout << *left.rbegin();

    for (int i = k; i < n; i++) {

        if (left.find(a[i - k]) != left.end())
            left.erase(left.find(a[i - k]));
        else
            right.erase(right.find(a[i - k]));

        if (left.empty() || a[i] <= *left.rbegin())
            left.insert(a[i]);
        else
            right.insert(a[i]);

        balance();

        cout << " " << *left.rbegin();
    }

    cout << '\n';

    return 0;
}