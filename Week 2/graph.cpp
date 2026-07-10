#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ofstream my_file("graph.txt");
/*
 1 -- 2
 |    |
 3 -- 4
      |
      5 
*/

class Graph{
    int V;
    list<int> *l; //dynamic array

    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V + 1];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i = 1; i <= V; i++){
            my_file << i <<" : ";
            for(auto item : l[i]){
                my_file << item <<" ";
            }
            my_file << endl;
        }
    }
    //visit immediate unvisited neighbour
    void bfs(){
        queue<int>  q;
        vector<bool> visited(V + 1, false);
        visited[0] = true;
        visited[1] = true;
        //starting from 1
        q.push(1);
        while(q.size() > 0){
            int u = q.front();
            q.pop();
            my_file << u <<" ";
            for(auto v : l[u]){ //v is immediate neighbour
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        my_file << endl;
    }
    // go to first unvisited neighbour
    void dfsHelper(int u, vector<bool> &visited){
        my_file << u << " ";
        visited[u] = true;
        for(auto v : l[u]){
            if(!visited[v]){
                dfsHelper(v, visited);
            }
        }
    }
    void dfs(){
        vector<bool> visited(V + 1, false);
        dfsHelper(1, visited);
        my_file <<endl;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.printAdjList();
    my_file << "bfs : ";
    g.bfs(); // should give {1, 2, 3, 4, 5}
    my_file << "dfs : ";
    g.dfs(); // should give {1, 2, 4, 3, 5}
    return 0;
}
