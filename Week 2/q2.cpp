#include<iostream>
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
    int l=0,r=n-1;
    while (l < r) {
    int sum = a[l] + a[r];

    if (sum == x) {
        break;
    }

    if (sum < x)
        l++;
    else
        r--;
    }
    if (l >= r) {
    cout << "IMPOSSIBLE\n";
    return 0;
    }
    int first = -1, second = -1;

    for (int i = 0; i < n; i++) {
        if (b[i] == a[l] && first == -1)
            first = i;

        else if (b[i] == a[r] && (a[l] != a[r] || i != first))
            second = i;
}

cout << first + 1 << " " << second + 1 << '\n';
}
