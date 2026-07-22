#include <iostream>
#include<vector>
using namespace std;
void dfs(int u,vector<vector<pair<int,int>>> &adj,
         vector<bool> &visited,
         vector<bool> &usedEdge,
         vector<pair<int,int>> &edges,
         vector<pair<int,int>> &extra) {
    visited[u] = true;

    for (auto [v, id] : adj[u]) {

        if (usedEdge[id]) continue;
        usedEdge[id] = true;

        if (!visited[v]) {
            dfs(v,adj,visited,usedEdge,edges,extra);
        } else {
            extra.push_back(edges[id]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj;
    vector<pair<int,int>> edges;

    vector<bool> visited;
    vector<bool> usedEdge;

    vector<pair<int,int>> extra;
    vector<int> reps;
    adj.resize(n + 1);
    edges.resize(n - 1);

    visited.assign(n + 1, false);
    usedEdge.assign(n - 1, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        edges[i] = {u, v};

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(i,adj,visited,usedEdge,edges,extra);
        }
    }

    cout << reps.size() - 1 << '\n';

    for (int i = 0; i + 1 < reps.size(); i++) {
        auto [u, v] = extra[i];

        cout << u << ' ' << v << ' '
             << reps[i] << ' '
             << reps[i + 1] << '\n';
    }

    return 0;
}
