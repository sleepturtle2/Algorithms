#include <bits/stdc++.h>
#include "./graph_headers/weighted_DAG.h"
using namespace std;

int getweight(vector<vector<pair<int, int>>> &adj, int source, int dest)
{
    for (pair<int, int> p : adj[source])
        if (p.first == dest)
            return p.second;
    return INT_MIN;
}

void topologicalSortUtil(vector<vector<pair<int, int>>> &adj, int v, vector<bool> &visited, stack<int> &Stack)
{
    visited[v] = true;
    for (pair<int, int> p : adj[v])
        if (!visited[p.first])
        {
            topologicalSortUtil(adj, p.first, visited, Stack);
        }
    Stack.push(v);
}

void longestPath(vector<vector<pair<int, int>>> &adj, int V, int source)
{
  
    stack<int> Stack;
    vector<int> distance(V, INT_MIN);
    vector<bool> visited(V, false);

    //get the topo sort of DAG in stack
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(adj, i, visited, Stack);
   

    //all distance is -ve inf and distance to source is 0
    distance[source] = 0;

    //process vertices in topological order
    while (!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();

        //relax distances of all adjacent vertices
        if (distance[u] != INT_MIN)
        {
            for (pair<int, int> p : adj[u])
            {
                int v = p.first;
                if (distance[v] < distance[u] + getweight(adj, u, v))
                    distance[v] = distance[u] + getweight(adj, u, v);
            }
        }
    }

    cout << "Longest distances: \n";
    //print calculated longest distances
    for (int i : distance)
        i == INT_MIN ? cout << "-inf " : cout << i << " ";
    cout << "\n";
}

void shortestPath(vector<vector<pair<int, int>>> &adj, int V, int source)
{
  
    stack<int> Stack;
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);

    //get the topo sort of DAG in stack
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(adj, i, visited, Stack);
   

    //all distance is -ve inf and distance to source is 0
    distance[source] = 0;

    //process vertices in topological order
    while (!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();

        //relax distances of all adjacent vertices
        if (distance[u] != INT_MAX)
        {
            for (pair<int, int> p : adj[u])
            {
                int v = p.first;
                if (distance[v] > distance[u] + getweight(adj, u, v))
                    distance[v] = distance[u] + getweight(adj, u, v);
            }
        }
    }

    cout << "Shortest distances: \n";
    //print calculated shortest distances
    for (int i : distance)
        i == INT_MIN ? cout << "inf " : cout << i << " ";
    cout << "\n";
}

int main()
{
    Graph *g = new Graph();
    int V = g->V;
    vector<vector<pair<int, int>>> adj = g->adj;
    int source = 1;
    longestPath(adj, V, source);
    shortestPath(adj, V, source); 
    return 0;
}
