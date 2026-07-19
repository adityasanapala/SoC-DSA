#include <iostream>
using namespace std;

int leader[1005]; 

int Cycle(int city) {
    while (leader[city] != city) city = leader[city];
    return city;
}

void merge(int city1, int city2) {
    int i = Cycle(city1);
    int j = Cycle(city2);
    if (i != j) leader[i] = j; 
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        leader[i] = i;
    }

    int closeA[1005], closeB[1005]; 
    int Extra = 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        if (Cycle(a) == Cycle(b)) {
            closeA[Extra] = a;
            closeB[Extra] = b;
            Extra++;
        }
        else {
            merge(a, b);
        }
    }

    int group[1005];
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (Cycle(i) == i) {
            group[num] = i;
            num++;
        }
    }

    cout << Extra << "\n";
    for (int i = 0; i < Extra; i++) {
        cout << closeA[i] << " " << closeB[i] << " "
             << group[i] << " " << group[i + 1] << "\n";
    }

    return 0;
}