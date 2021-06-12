#include <bits/stdc++.h>
#include "./graph_headers/unweighted_DAG.h"
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj, int V, vector<int> &indegree)
{
    vector<int> topological;
    queue<int> Q;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            Q.push(i);

    while (!Q.empty())
    {
        int top = Q.front();
        Q.pop();

        topological.push_back(top);

        for (int i : adj[top])
        {
            indegree[i]--;

            if (indegree[i] == 0)
                Q.push(i);
        }
    }
    return topological;
}

void maximumEdgeAddition(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    vector<int> indegree(V, 0);

    for (vector<int> v : adj)
        for (int i : v)
            indegree[i]++;

    vector<int> topo = topologicalSort(adj, V, indegree);

    for (int u = 0; u < topo.size(); u++)
    {

        int t = topo[u];
        //looping through adjacent nodes of u
        for (int v = 0; v < adj[t].size(); v++)
            visited[v] = true;

        //mark all unmarked nodes as printed
        for (int w = u + 1; w < adj[t].size(); w++)
        {
            if (!visited[topo[w]])
                cout<<t<<"-"<<topo[w]<<" "; 
            
            visited[topo[w]] = false; 
        }
    }
    cout<<"\n"; 
}

int main()
{
    Graph *g = new Graph();
    vector<vector<int>> adj = g->adj;
    int V = g->V;
    maximumEdgeAddition(adj, V);
    return 0;
}
