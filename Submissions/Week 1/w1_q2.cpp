#include <iostream>
#include <string>
using namespace std;

int main()
{
    string dna;
    cin >> dna;

    int maxCount = 1;
    int currentCount = 1;

    for (int i = 1; i < dna.length(); i++)
    {
        if (dna[i] == dna[i - 1])
        {
            currentCount++;
        }
        else
        {
            currentCount = 1;
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
        }
    }

    cout << maxCount;

    return 0;
}