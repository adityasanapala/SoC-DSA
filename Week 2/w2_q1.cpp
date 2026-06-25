  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>
  using namespace std;



int main() {
    int n;
    cin>>n;
    int arr[n];

    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v.push_back({arr[i]});
    }
    set<int> s;

    int l=0,ans=0;

    for(int r=0;r<n;r++){         //using sliding window with [l,r]
        while(s.count(v[r])){     //erasing the repetetive song
            s.erase(v[l]);
            l++;        //increasing the left side till the window has no repetetion
        }

        s.insert(v[r]);
        ans=max(ans,r-l+1);


    }
    cout<<ans;






}
