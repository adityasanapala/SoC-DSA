#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
vector<pair<int,int>> extra;
vector<int> visited;

void dfs(int node, int parent){
    visited[node] = 1;
    for(auto child : graph[node]){
        if(child == parent) continue;
        if(visited[child]){
            if(node < child) extra.push_back({node, child});
        }
        else{
            dfs(child, node);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.assign(n+1, 0);
    vector<int> components;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            components.push_back(i);
            dfs(i,-1);
        }
    }
    int ans = components.size() - 1;
    cout<<ans<<endl;
    for(int i = 0; i < ans; i++){
        auto removed = extra[i];
        cout<<removed.first<<" "<<removed.second<<" "<<components[0]<<" "<<components[i+1]<<endl;
    }
    return 0;
}