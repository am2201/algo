#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<list<int>> adj;
    vector<bool> visited;

    Graph(int v)
    {
        this->v = v;
        adj.resize(v);
        visited.resize(v, false);
    }

    void addEdge(int v, int e)
    {
        adj[v].push_back(e);
    }

    void dfs(int s)
    {
        visited[s] = true;
        cout << s << " ";
        for (auto i : adj[s])
        {
            if (visited[i] != true)
                dfs(i);
        }
    }
};
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";

    // Function call
    g.dfs(2);

        return 0;
}