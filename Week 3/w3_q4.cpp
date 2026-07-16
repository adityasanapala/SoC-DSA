  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>


using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<int> prev(m + 1), cur(m + 1);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++) {
        cur[0] = i;

        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                cur[j] = prev[j - 1];
            } else {
                int insertOp = cur[j - 1];
                int deleteOp = prev[j];
                int replaceOp = prev[j - 1];

                cur[j] = 1 + min({insertOp, deleteOp, replaceOp});
            }
        }

        swap(prev, cur);
    }

    cout << prev[m] << '\n';
    return 0;
}
