#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<string> lines;
   string s;
   bool left = false;
   bool right = true;
   while(getline(cin, s)){
    lines.push_back(s);
   }
   int width = 0;
   int n = lines.size();
   for(int i = 0; i < n; i++){
    width = max(width, (int)lines[i].length());
   }
   vector<int> spaces(n);
   for(int i = 0; i < n; i++){
    spaces[i] = width-lines[i].length();
   }
   for(int i = 0; i < (width+2); i++){
    cout<<'*';
   }
   cout<<endl;
   for(int i = 0; i < n; i++){
    int sps = spaces[i]/2;
    if(spaces[i] % 2 == 0){
        cout<<'*';
        cout<<setw(sps + lines[i].size())<<lines[i];
        cout<<setw(sps + 1)<<'*';
        cout<<endl;
    }else{
        if(right == true){
            cout<<'*';
            cout<<setw(sps + lines[i].size())<<lines[i];
            cout<<setw(sps+2)<<'*';
            right = false;
            left = true;
            cout<<endl; 
        }else{
            cout<<'*';
            cout<<setw(sps+1 + lines[i].size())<<lines[i];
            cout<<setw(sps+1)<<'*';
            right = true;
            left = false;
            cout<<endl;
        }
    }
   }
   for(int i = 0; i < (width+2); i++){
    cout<<'*';
   }
   cout<<endl;
   return 0;
}