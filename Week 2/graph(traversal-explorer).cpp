#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class graph{
    int v;
    list<int>* l;
    public:
    graph(int v){
        this->v = v;
        l = new list<int>[v+1];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(int x){
        vector<bool> vis(v+1);
        queue<int> q;
        q.push(x);
        vis[x] = true;
        while(q.size() > 0){
            int u = q.front();
            q.pop();
             cout<<u<<" ";
             for(int y : l[u]){
                if(!vis[y]){
                    vis[y] = true;
                    q.push(y);
                }
             }
        }
    }

    void dfsHelper(int u, vector<bool>& vis){
        cout<<u<<" ";
        vis[u] = true;
        for(int y : l[u]){
            if(!vis[y]){
                dfsHelper(y, vis);
            }
        }
    }

    void dfs(int x){
        int u = x;
        vector<bool> vis(v+1);
        dfsHelper(u, vis);
    }
};

int main(){
    graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(1);
    cout<<endl;
    g.dfs(1);
    cout<<endl;

    
    return 0;
}