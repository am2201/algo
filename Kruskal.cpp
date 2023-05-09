#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

class Graph {
private:
    int V;
    vector<Edge> edges;
    
public:
    Graph(int V) {
        this->V = V;
    }
    
    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }
    
    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }
    
    void Union(Subset subsets[], int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
        
        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
        } else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    
    void kruskal() {
        vector<Edge> result;
        
        // Sort the edges by weight in non-decreasing order
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });
        
        // Allocate memory for subsets
        Subset* subsets = new Subset[V];
        for (int i = 0; i < V; i++) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }
        
        // Iterate through each edge and add it to the result if it doesn't form a cycle
        for (int i = 0; i < edges.size(); i++) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int src_root = find(subsets, src);
            int dest_root = find(subsets, dest);
            
            if (src_root != dest_root) {
                result.push_back(edges[i]);
                Union(subsets, src_root, dest_root);
            }
        }
        
        // Print the minimum spanning tree
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].src << " -- " << result[i].dest << "  " << result[i].weight << endl;
        }
        
        delete[] subsets;
    }
};

int main() {
    // Example usage
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.kruskal();
    return 0;
}
