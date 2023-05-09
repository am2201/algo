#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

class Graph {
private:
    int V;
    vector<pair<int, int>>* adj;
    
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    void dijkstra(int src) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;
                
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        
        cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
};

int main() {
    // Example usage
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.dijkstra(0);
    return 0;
}
