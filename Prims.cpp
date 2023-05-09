#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> calculatePrimsMST(int n, map<int, vector<pair<int, int>>> adj)
{
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    key[1] = 0;

    // iterating over the adj list (note the loop limits)
    for (int i = 1; i < n; i++)
    {
        // now finding the node with minimum key value which is not in tree(mst is false)
        int u;
        int mini = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!mst[j] && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }
        mst[u] = true; // including the min node in tree(marking its mst as true)
        // now checking its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<int, pair<int, int>>> result;
    for (int i = 2; i <= n; i++)
        // result.push_back(make_pair(make_pair(parent[i], i), key[i]));
        result.push_back({key[i], {i, parent[i]}});
    return result;
}

int main()
{
    cout << "E: ";
    int e;
    cin >> e;
    cout << "V: ";
    int n;
    cin >> n;
    int u, v, w;
    map<int, vector<pair<int, int>>> adj; // adjacency list
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<pair<int, pair<int, int>>> ans = calculatePrimsMST(n, adj);
    int weight = 0;
    cout << "Edges in the min spanning tree: \n";
    for (auto it : ans)
    {
        weight += it.first;
        cout << it.second.first << " " << it.second.second << " " << it.first << endl;
    }
    cout << "Sum of weights : " << weight;
}