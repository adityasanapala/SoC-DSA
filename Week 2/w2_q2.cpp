  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  using namespace std;



  int main(){
    int n,x;
     cin>>n>>x;
    int arr[n];
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
      cin>>arr[i];
      v.push_back({arr[i],i});
  }

    sort(v.begin(),v.end());
    int answer1;
    int answer2;

    for(int i=0;i<n;i++){
      int k=x-v[i].first;


          int a=i+1,b=n-1;
          while(a<=b){
            int p=(a+b)/2;
            if(v[p].first==k){
              answer1=v[i].second;
              answer2=v[p].second;
              cout<<answer1+1<<" "<< answer2+1;
              return 0;
            }
            if(v[p].first>k)b=p-1;
            else a=p+1;



      }

      }
      cout<<"IMPOSSIBLE";


    }
