#include <iostream>
using namespace std;

int main()
{
  long long n;
  cin>>n;
  
  long long num=0,sum=0;
  for (int i=1;i<n;i++)
  {
    cin>>num;
    sum += num;
  }
  long long missing_num = (n*(n+1)/2) - sum;
  cout<<missing_num;
}

"""
BruteForce Method Used

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n - 1];

    for(int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    for(int num = 1; num <= n; num++)
    {
        bool found = false;

        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] == num)
            {
                found = true;
                break;
            }
        }

        if(found == false)
        {
            cout << num;
            break;
        }
    }
}
"""

