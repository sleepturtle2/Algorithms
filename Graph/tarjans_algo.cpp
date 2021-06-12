#include<bits/stdc++.h>
#include "unweighted_directed.h"
using namespace std; 

void SCCUtil(vector<vector<int>>&adj, int V, int u, vector<int>&disc, vector<int>&low, stack<int>&Stack, vector<bool>&stackMember ){
    
    static int time = 0; 
    disc[u] = low[u] = ++time; 
    Stack.push(u); 
    stackMember[u] = true; 

    for(int v : adj[u]){
        
        //if v is not visited yet, recur for it
        if(disc[v] == -1){
            SCCUtil(adj, V, v, disc, low, Stack, stackMember); 

            //check if the subtree rooted with v has a connection to one of the ancestors of u 
            low[u] = min(low[u], low[v]); 
        }

        //update low value of u only if v is still in stack, means it is a back-edge, not a cross edge
        else if(stackMember[v]==true)
        low[u] = min(low[u], disc[v]); 
    }

    //head node found, pop the stack and print an SCC 
    int w = 0; 
    if(low[u] == disc[u]){
        while(Stack.top() != u){
            w = Stack.top(); 
            cout<<w<<" "; 
            stackMember[w] = false; 
            Stack.pop(); 
        }

        w = Stack.top(); 
        cout<<w<<"\n"; 
        stackMember[w] = false; 
        Stack.pop(); 
    }
}

void SCC(vector<vector<int>>&adj, int V){
    vector<int>disc(V, -1); 
    vector<int>low(V, -1); 
    vector<bool>stackMember(V); 
    stack<int>Stack; 

    for(int i=0; i<V; i++)
    if(disc[i] == -1)
    SCCUtil(adj, V, i, disc, low, Stack, stackMember); 
}

int main(){
    Graph* g = new Graph(); 
    vector<vector<int>>adj = g->adj3; 
    int V = adj.size();  
    SCC(adj, V); 
    return 0; 
}