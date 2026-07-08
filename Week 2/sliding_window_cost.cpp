#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<long long> left, right;

    long long sumLeft = 0;
    long long sumRight = 0;

    auto balance = [&]() {

        while (left.size() > right.size() + 1) {

            auto it = prev(left.end());

            right.insert(*it);

            sumLeft -= *it;
            sumRight += *it;

            left.erase(it);
        }

        while (left.size() < right.size()) {

            auto it = right.begin();

            left.insert(*it);

            sumRight -= *it;
            sumLeft += *it;

            right.erase(it);
        }
    };

    auto add = [&](long long x) {

        if (left.empty() || x <= *left.rbegin()) {

            left.insert(x);
            sumLeft += x;
        }
        else {

            right.insert(x);
            sumRight += x;
        }

        balance();
    };

    auto remove = [&](long long x) {

        if (left.find(x) != left.end()) {

            left.erase(left.find(x));
            sumLeft -= x;
        }
        else {

            right.erase(right.find(x));
            sumRight -= x;
        }

        balance();
    };

    for (int i = 0; i < k; i++) {
        add(a[i]);
    }

    auto printCost = [&]() {

        long long median = *left.rbegin();

        long long cost = median * (long long)left.size() - sumLeft;

        cost += sumRight - median * (long long)right.size();

        cout << cost;
    };

    printCost();

    for (int i = k; i < n; i++) {

        remove(a[i - k]);

        add(a[i]);

        cout << " ";

        printCost();
    }

    cout << '\n';

    return 0;
}