  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  using namespace std;



int main() {
 long long n
    ;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    long long m=arr[n/2];
    long long x=0;

    for(long long i=0;i<n;i++){
        x+=abs(m-arr[i]);
    }
    cout<<x;
}

