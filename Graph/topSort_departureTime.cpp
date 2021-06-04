#include<bits/stdc++.h>
#include "unweighted_DAG.h"
using namespace std;

void dfs(int v, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&departure, int &time){
    visited[v] = true; 

    for(int i : adj[v])
    if(!visited[i])
    dfs(i, adj, visited, departure, time); 

    departure[time--] = v; 
}

void topSort(vector<vector<int>>&adj, int V){
    vector<bool>visited(V, false); 
    vector<int>departure(V, -1); 
    int time = V-1; 

    for(int i=0; i<V; i++)
    if(!visited[i])
    dfs(i, adj, visited, departure, time); 

    for(int i: departure)
    cout<<i<<" "; 
    cout<<"\n"; 
}

int main(){
    Graph* g = new Graph(); 
    vector<vector<int>>adj = g->adj; 
    int V = g->V; 
    cout<<"Topological Sort:\n"; 
    topSort(adj, V);
    return 0; 
}