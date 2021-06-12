//https://www.geeksforgeeks.org/topological-sorting/

#include<bits/stdc++.h>
//should work with weights too
#include "./graph_headers/unweighted_DAG.h"
using namespace std; 

//O(V+E)

//DFS
void topSortUtil(int v, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&Stack){
    visited[v] = true; 

    for(int i=0; i<adj[v].size(); i++)
    if(!visited[i])
    topSortUtil(i, adj, visited, Stack); 

    Stack.push(v); 

}

void topSort(vector<vector<int>>&adj, int V){
    stack<int> Stack; 
    vector<bool> visited (V, false);

    for(int i=0; i<V; i++)
    if(!visited[i])
    topSortUtil(i, adj, visited, Stack); 

    while(!Stack.empty()){
        cout<<Stack.top()<<" "; 
        Stack.pop(); 
    }
    cout<<"\n"; 
}

int main(){
    Graph* g=new Graph(); 
    vector<vector<int>>adj = g->adj; 
    int V = g->V; 

    cout<<"Topological Sort: \n"; 
    topSort(adj, V); 

    return 0; 
}
