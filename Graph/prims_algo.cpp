#include<bits/stdc++.h>
#include "./graph_headers/weighted_undirected.h"
#define mp make_pair
using namespace std; 

void primsAlgo(vector<vector<pair<int,int>>>&adj, int V){
    int total_weight = 0;
    vector<pair<int,int>>min_e(V, mp(INT_MAX, -1)); //stores minimum incoming edge; 
    set<pair<int,int>> Q; //stores minimum outgoing weight in (weight,to) form

    Q.insert(mp(0,0)); //weight to source, source
    vector<bool>selected(V, false); 

    for(int i=0; i<V; i++){
        if(Q.empty()){
            cout<<"No MST\n"; 
            return; 
        }

        int v = Q.begin()->second; 
        selected[v] = true; 
        total_weight += Q.begin()->first; 
        Q.erase(Q.begin()); 

        if(min_e[v].second != -1)
            cout<<"-> "<<v<<"-"<<min_e[v].second<<endl; 
        
        for(auto e : adj[v]){
            if(!selected[e.first] && e.second < min_e[e.first].first){
                Q.erase(mp(min_e[e.first].first, e.first)); 
                min_e[e.first] = mp(e.second, v); 
                Q.insert({e.second, e.first}); 
            }
        }

    }
    cout<<"Total weight: "<<total_weight<<endl; 
}

int main()
{
    Graph* g = new Graph(); 
    vector<vector<pair<int, int>>> adj = g->adj; 
    vector<vector<int>>edge = g->edge; 
    int V = g->V; 
    primsAlgo(adj, V); 
    return 0; 
}
