#include<bits/stdc++.h>
#include "neg_weighted_directed.h"
using namespace std;

//For Bellman-Ford, you supply edges, not adjacency list for vertices
void shortestPath(int V, int E, vector<edge>&e, int source)
{
	vector<int> dist(V, INT_MAX);
	
	for(int i=1; i<=V-1; i++)
	for(int j=0; j<E; j++)
	if(dist[e[j].u]!=INT_MAX && dist[e[j].v]>dist[e[j].u]+e[j].weight)
	dist[e[j].v]=dist[e[j].u]+e[j].weight;
	
	bool found=false; //no negative cycle found 
	//check for negative cycles 
	for(int i=0; i<E; i++)
	if(dist[e[i].v]>dist[e[i].u]+e[i].weight)
	{
		found=true;
		cout<<"Negative weight cycle found\n";
		break;
	}
	if(!found)
	for(int i=0; i<V; i++)
	cout<<i<<"  "<<dist[i]<<"\n";
}

int main()
{
	Graph* g=new Graph();
	vector<edge>e=g->e;
	int V=g->V;
	int E=g->E;
	int source=0;
	shortestPath(V, E, e, source);
	
}
