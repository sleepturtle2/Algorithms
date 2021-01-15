#include<bits/stdc++.h>

#define vi vector<int>
#define pb push_back
using namespace std;

void DFS(vector<int>adj[], int u, vi &disc, vi &low, vi &parent, vector<bool>&articulation_points)
{
	static int time=0; //initialised only once, ignored the following times
	disc[u]=low[u]=time;
	time+=1;
	int children=0;
	
	for(int v : adj[u])
	{
		if(disc[v]==-1) //not yet discovered
		{
			children+=1;
			parent[v]=u;
			DFS(adj, v, disc, low, parent, articulation_points);
			
			low[u]=min(low[u], low[v]); //if v or subgraph of v has a back-edge
			
			if(parent[u]==-1 and children>1) //Case 1: u is root and at least 2 children
			articulation_points[u]=true;
			
			if(parent[u]!=-1 and low[v]>=disc[u]) //Case 2: Atleast 1 component will get separated
			articulation_points[u]=true;
		}
		
		else if(v!=parent[u]) //ignore child to parent edge 
		low[u]=min(low[u], disc[v]);
	}
}

void tarjansAlgo(int v, vector<int>adj[])
{
	//disc = discovery array 
	//low=lowest time array 
	vector<int> disc(v,-1), low(v,-1), parent(v,-1);
	vector<bool>articulation_points(v, false);
	
	for(int i=0; i<v;i++)
	if(disc[i]==-1)
	DFS(adj, i, disc, low, parent, articulation_points);
	
	cout<<"Articulation Points are\n";
	for(int i=0; i<v;i++)
	if(articulation_points[i])
	cout<<i<<" ";
	cout<<"\n";
}

int main()
{
	int v=5;
	vector<int>adj[v];
	
	adj[0].pb(2);
	adj[2].pb(0);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[1].pb(0);
	adj[0].pb(1);
	adj[2].pb(1);
	adj[1].pb(2);
	adj[3].pb(4);
	adj[4].pb(3);
	
	tarjansAlgo(v, adj);
		return 0;
}
//O(V+E)
