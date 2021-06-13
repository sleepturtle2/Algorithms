//https://codeforces.com/blog/entry/71146

#include <bits/stdc++.h>
#include "./graph headers/unweighted_undirected.h"
using namespace std;

// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points

void APUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap)
{
    static int time = 0;
    int children = 0;
    visited[u] = true;

    disc[u] = low[u] = ++time;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(adj, v, visited, disc, low, parent, ap);

            //check if the subtree rooted with v has a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            //u is articulation point in following cases

            //u is root of DFS tree and has two or more children
            if (parent[u] == -1 && children > 1)
                ap[u] = true;

            //if u is not root and low value of one of its child is more than discovery value of u
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }

        //update low value of u for parent function calls
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void AP(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V);
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> parent(V, -1);
    vector<bool> ap(V); //to store articulation points

    //call util function to find articulation points in DFS tree rooted with vertex i
    for (int i = 0; i < V; i++)
        if (!visited[i])
            APUtil(adj, i, visited, disc, low, parent, ap);

    //now ap[] contains articulation points, print them
    for (int i = 0; i < V; i++)
        if (ap[i])
            cout << i << " ";

    cout << "\n";
}

int main()
{
    Graph *g = new Graph();
    vector<vector<int>> adj = g->adj2;
    int V = adj.size();
    AP(adj, V);
    return 0;
}
