#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    long long w;
    int v;
    double ratio;
};

int n;
long long W;
vector<Item> items;
int max_value = 0;

// Helper function to calculate the greedy upper bound from index 'idx' with remaining capacity 'rem_W'
double get_upper_bound(int idx, long long rem_W, int current_value) {
    double bound = current_value;
    long long w_sum = 0;
    
    for (int i = idx; i < n; i++) {
        if (w_sum + items[i].w <= rem_W) {
            w_sum += items[i].w;
            bound += items[i].v;
        } else {
            // Take the fractional part of the item using its ratio
            long long remaining_space = rem_W - w_sum;
            bound += remaining_space * items[i].ratio;
            break;
        }
    }
    return bound;
}

// DFS Branch and Bound Search
void solve_search(int idx, long long rem_W, int current_value) {
    // Update the maximum value found so far
    if (current_value > max_value) {
        max_value = current_value;
    }
    
    // Base case
    if (idx == n) return;
    
    // Pruning: If the best possible ideal value from here can't beat our max_value, stop
    if (get_upper_bound(idx, rem_W, current_value) <= max_value) {
        return;
    }
    
    // Choice 1: Take the item (if it fits)
    if (rem_W >= items[idx].w) {
        solve_search(idx + 1, rem_W - items[idx].w, current_value + items[idx].v);
    }
    
    // Choice 2: Do not take the item
    solve_search(idx + 1, rem_W, current_value);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> W)) return 0;

    items.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].w >> items[i].v;
        items[i].ratio = (double)items[i].v / items[i].w;
    }

    // Sort items by value/weight ratio in descending order
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    solve_search(0, W, 0);

    cout << max_value << "\n";

    return 0;
}