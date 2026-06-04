#include <iostream>
using namespace std;

int main()
{
    long long c;
    cin>>c;
    for (long long i=0;i< c;i++)
    {
      long long n,k;
      cin>>n>>k;
      if (k % 2 == 0) 
            cout << (n % 2 == 0 ? "YES \n" : "NO \n");
      else 
      {
            if (n % 2 == 0 || n >= k)
                cout << "YES\n";
            else
                cout << "NO\n";
      }
          
    }
}