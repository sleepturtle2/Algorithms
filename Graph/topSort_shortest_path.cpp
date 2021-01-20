#include<bits/stdc++.h>
#include "weighted_DAG.h"
using namespace std;

void DFS(vector<vector<pair<int,int>>> adj, int node, vector<bool>&visited, deque<int>&top_sort)
{
	visited[node]=true;
	
	for(auto i=adj[node].begin(); i!=adj[node].end(); i++)
	if(!visited[(*i).first])
	DFS(adj, (*i).first, visited,  top_sort);
	
	top_sort.push_front(node);
	}
	

void shortestPath(vector<vector<pair<int,int>>> adj, int V, int source)
{
	
	vector<bool>visited(V, false);
	deque<int>top_sort; //we could have also used stack instead
	
	for(int i=0; i<V; i++)
	if(!visited[i])
	DFS(adj, i, visited,  top_sort);
	
	/*
	cout<<"Top Sort\n";
	for(int i: top_sort)
	cout<<i<<" ";
	cout<<"\n";
	*/
	
	vector<int>dist(V, INT_MAX);
	dist[source]=0;
	
	while(!top_sort.empty())
	{
		int u=top_sort.front(); 
		top_sort.pop_front();
		 cout<<u<<"->";		 
		if(dist[u]!=INT_MAX)
		for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
		dist[(*i).first]=min(dist[(*i).first], dist[u]+(*i).second);
			
		
	}
	
	//print distnace array
	for(int i=0; i<V; i++)
	{
		if(dist[i]==INT_MAX)
		cout<<i<<"\tINF\n";
		else
		cout<<i<<"\t"<<dist[i]<<"\n";
	}
	cout<<"\n";
}
		
	
	
int main()
{
	Graph* g=new Graph();
	vector<vector<pair<int,int>>> adj=g->adj;
	int V=g->V;
	int source=0;
	shortestPath(adj, V, source);
	return 0;
	}
