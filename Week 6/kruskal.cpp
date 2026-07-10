#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Edge{
    public:
    int u, v, wt;
    Edge(int u, int v, int wt){
        this -> u = u;
        this -> v = v;
        this -> wt = wt;
    }
    //comparator for sorting the edges by weight
    bool operator<(const Edge &other) const{
        return this -> wt < other.wt;
    }
};

class Graph{ //using an edge list for this algorithm
    public:
    int V;
    vector<Edge> edges;
    vector<int> parent, rank;

    Graph(int V){
        this -> V = V;

        for(int i = 0; i < V; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }

    int find(int n){
        int p = parent[n];
        if(p == n) return p;
        return parent[n] = find(parent[n]); //path compression
    }

    void dsunion(int u, int v){ //union is a cpp keyword
        int a = find(u);
        int b = find(v);
        
        if(a == b) return;
        if(rank[a] == rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else if (rank[a] > rank[b]){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }
    }

    int kruskal(){
        sort(edges.begin(), edges.end());
        int mst_cost = 0;
        for(auto e : edges){
            int a = find(e.u);
            int b = find(e.v);

            if(a != b){// not a cycle so union
                dsunion(e.u, e.v);
                mst_cost += e.wt;
            }
        }
        return mst_cost;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    Graph graph(4);

    /*
     *  the graph constructed along with the edge weights
     *         0
     *      /  |  \
     *   10/   |5  \6
     *    /    |    \
     *   1 --- 3 --- 2
     *     15     4
     * 
     * kruskal's algorithm will use the edges of weights 4, 5 and 10
     */

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    cout << graph.kruskal() <<endl;
    return 0;
}
