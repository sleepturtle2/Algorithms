//https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/

#include <bits/stdc++.h>
#include "./graph headers/unweighted_directed.h"
using namespace std;

void DFSUtil(vector<vector<int>> &adj, int V, int u, vector<bool> &visited)
{
    visited[u] = true;

    for (int v : adj[u])
        if (!visited[v])
            DFSUtil(adj, V, v, visited);
}

vector<vector<int>> getTranspose(vector<vector<int>> &adj, int V)
{
    vector<vector<int>> new_adj(V);

    for (int v = 0; v < V; v++)
        for (int i : adj[v])
            new_adj[i].push_back(v);

    return new_adj;
}

void print(vector<vector<int>>&adj){
    for(int i=0; i<adj.size(); i++)
    {
        cout<<i<<"->"; 
        for(int v : adj[i])
        cout<<v<<" "; 
        cout<<"\n"; 
    }
}

bool isSC(vector<vector<int>>&adj, int V)
{
    //all vertices are not visited for first DFS
    vector<bool>visited(V);
    
    //DFS traversal, starting from first vertex
    DFSUtil(adj, V, 0, visited);

    //if DFS traversal does not visit all vertices then return false
    for (int i = 0; i < V; i++)
        if (!visited[i])
                return false;
            
    //get adjacency list of transpose graph
    vector<vector<int>> new_adj = getTranspose(adj, V);

    
    //mark all vertices as not visited
    visited.assign(V, false);

    //Do DFS traversal of the reversed graph starting from the first vertex
    DFSUtil(new_adj, V, 0, visited);

    //if all vertices are not visited in second DFS, then return false
    for (int i = 0; i < V; i++)
        if (!visited[i])
            return false;
    return true;
}

int main()
{
    Graph *g = new Graph();
    vector<vector<int>> adj = g->adj4;
    int V = adj.size(); 
    isSC(adj, V) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}