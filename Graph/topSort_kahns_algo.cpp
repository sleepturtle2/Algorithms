#include <bits/stdc++.h>
//works also with weights
#include "./graph_headers/unweighted_DAG.h"
using namespace std;

void print_queue(queue<int> Q)
{
    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << "\n";
}
void topSort_Kahn(vector<vector<int>> &adj, int V)
{
    vector<int> in_degree(V, 0);

    for (vector<int> i : adj)
        for (int j : i)
            in_degree[j]++;

    queue<int> Q;

    for (int i = 0; i < in_degree.size(); i++)
        if (in_degree[i] == 0)
            Q.push(i);

    int count = 0; //redundant if graph is surely DAG
    vector<int> top_order;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        top_order.push_back(u);

        for (int i : adj[u])
        {
            in_degree[i]--;
            if (in_degree[i] == 0)
                Q.push(i);
        }
        count++;
    }
    if (count != V)
    {
        cout << "Graph has cycles\n";
    }
    else
    {
        for (int i : top_order)
            cout << i << " ";
        cout << "\n";
    }
}

int main()
{
    Graph *g = new Graph();
    int V = g->V;
    vector<vector<int>> adj = g->adj;
    cout<<"Topoloigical Sort:\n";
    topSort_Kahn(adj, V);
    return 0;
}
