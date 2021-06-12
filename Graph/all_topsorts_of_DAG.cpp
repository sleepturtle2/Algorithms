#include <bits/stdc++.h>
#include "./graph_headers/unweighted_DAG.h"
using namespace std;

//exponential time complexity 


void printPath(list<int>path){
    while(!path.empty()){
        cout<<path.front()<<" "; 
        path.pop_front(); 
    }
    cout<<"\n";
}
void findAllTopologicalSorts(vector<vector<int>> &adj, vector<int>&in_degree, list<int> &path, vector<bool> &discovered, int V)
{
    //do for every vertex
    for (int v = 0; v < V; v++)
    {
        //proceed only if the current node's in-degree is 0 and is not processed
        if (in_degree[v]==0 && !discovered[v]){

            //reduce in-degree of every adjacent vertex 
            for(int u: adj[v])
            in_degree[u]--; 

            //include current node and mark as discovered
            path.push_back(v); 
            discovered[v]=true; 

            //recur
            findAllTopologicalSorts(adj, in_degree, path, discovered, V); 

            //reset in-degree for current node 
            for(int u : adj[v])
            in_degree[u]++; 

            //remove current node from path and mark it as undiscovered 
            path.pop_back(); 
            discovered[v] = false; 
        }
    }

    //print topological order if all vertices are included in the path 
    if(path.size() == V)
    printPath(path); 
}

void printAllTopologicalSorts(vector<vector<int>> &adj, int V)
{
    vector<bool> discovered(V, false);
    list<int> path;
    vector<int> in_degree(V);

    for (vector<int> u : adj)
        for (int v : u)
            in_degree[v]++;

    findAllTopologicalSorts(adj, in_degree, path, discovered, V);
}

int main()
{
    Graph *g = new Graph();
    vector<vector<int>> adj = g->adj;
    int V = g->V;
    cout << "All topological sorts of a graph are: \n";
    printAllTopologicalSorts(adj, V);
    return 0;
}
