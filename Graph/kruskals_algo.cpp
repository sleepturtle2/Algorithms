#include <bits/stdc++.h>
#include "./graph_headers/weighted_undirected.h"
using namespace std;

void make_set(int v, vector<int> &parent, vector<int> &rank)
{
    parent[v] = v;
    rank[v] = 0;
}

bool myComp(vector<int> a, vector<int> b)
{
    return a[2] > b[2];
}

int find_set(vector<int> &parent, int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vector<int> &parent, vector<int> &rank, int a, int b)
{
    a = find_set(parent, a);
    b = find_set(parent, b);

    if (a != b)
    {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void kruskalsAlgo(vector<vector<int>> &edge, int V)
{
    int cost = 0;
    vector<int> parent(V), rank(V);
    vector<vector<int>> E, result; //to store edges in (from, to, weight) format

    for (int i = 0; i < V; i++)
        make_set(i, parent, rank);

    sort(edge.begin(), edge.end(), myComp);

    for (vector<int> e : edge)
    {
        if (find_set(parent, e[0]) != find_set(parent, e[1]))
        {
            cost += e[2]; //weight
            result.push_back(e);
            union_sets(parent, rank, e[0], e[1]);
        }
    }

    for (vector<int> i : result)
        cout << i[0] << "," << i[1] << "-> " << i[2] << "\n";
    cout<<"Cost: "<<cost<<endl; 
}

int main()
{
    Graph *g = new Graph();
    vector<vector<int>> edge = g->edge;
    int V = g->V;
    kruskalsAlgo(edge, V);
    return 0;
}
