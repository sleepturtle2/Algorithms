#include<bits/stdc++.h>
#include "./graph_headers/weighted_directed.h"

#define pii pair<int,int>
#define mp make_pair
#define vi vector<int>
#define vvpii vector<vector<pii>>
using namespace std;

void shortestPath(vvpii adj, int V, int source)
{
	vi dist(V, INT_MAX); //initially all are unreachable 
	
	//use set or min-heap to search for minimum weight in log(size) time 
	set<pii> set; // (weight,vertex) format, because you wanna sort by weight 
	
	set.insert(mp(0,source));
	dist[source]=0;
	
	while(!set.empty()) // alternatively we can run for loop V-1 times 
	{
		pii curr=*(set.begin());
		set.erase(set.begin());
		int u=curr.second;
				
		for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
		{
			int v=(*i).first;
			int weight=(*i).second;
			
			if(dist[v]>dist[u]+weight) //relax edges 
			{
				if(dist[v]!=INT_MAX) //delete the existing weight on v because it's not the smallest 
				set.erase(set.find(mp(dist[v],v)));
				
				//update dist with the new smallest 
				dist[v]=dist[u]+weight;
				set.insert(mp(dist[v],v));
			}
		}
	}
	
	
	cout<<"Vertex\tDistance from Source "<<source<<endl;
	for(int i=0; i<V; i++)
	cout<<i<<"\t"<<dist[i]<<"\n";
}
				
int main()
{
	Graph* g=new Graph();
	vvpii adj=g->adj;
	int V=g->V;
	int source=0;
	shortestPath(adj, V, source);
	return 0;
}

//O(V+E)log V
