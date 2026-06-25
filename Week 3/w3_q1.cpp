  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>

  using namespace std;

int main(){

  long long n;
  cin>>n;
  vector<pair<long long,long long>> p;
  for(int i=0;i<n;i++){
    long long x,y;
    cin>>x>>y;
    p.push_back({x,y});

  }
  sort(p.begin(),p.end());

  long long ans=0;
  for(long long i=0;i<n;i++){
    ans+=p[i].second-p[i].first;
    if(i!=n-1)
    p[i+1].first+=p[i].first;
  }
  cout<<ans;




}
