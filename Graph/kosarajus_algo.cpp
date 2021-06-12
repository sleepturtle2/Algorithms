#include <bits/stdc++.h>
#include "./graph headers/unweighted_directed.h"
using namespace std;

void DFSUtil(vector<vector<int>> &new_adj, int v, vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " ";

    for (int i : new_adj[v])
        if (!visited[i])
            DFSUtil(new_adj, i, visited);
}

vector<vector<int>> getTranspose(vector<vector<int>> &adj, int V)
{
    vector<vector<int>> new_adj(V);
    for (int v = 0; v < V; v++)
    {
        for (int i : adj[v])
        {
            new_adj[i].push_back(v);
        }
    }
    return new_adj;
}
void fillOrder(vector<vector<int>> &adj, int v, vector<bool> &visited, stack<int> &Stack)
{
    visited[v] = true;

    for (int i : adj[v])
        if (!visited[i])
            fillOrder(adj, i, visited, Stack);

    Stack.push(v);
}

void printSCCs(vector<vector<int>> &adj, int V)
{
    stack<int> Stack;
    vector<bool> visited(V, false);

    //fill vertices in stack according to their finishing time
    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(adj, i, visited, Stack);

    vector<vector<int>> new_adj(V);
    new_adj = getTranspose(adj, V);

    visited.assign(V, false);

    while (!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v])
        {
            DFSUtil(new_adj, v, visited);
            cout << endl;
        }
    }
}

int main()
{
    Graph *g = new Graph();
    int V = g->adj2.size();
    vector<vector<int>> adj = g->adj2;
    printSCCs(adj, V);
    return 0;
}