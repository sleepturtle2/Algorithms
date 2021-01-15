#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define pb push_back

using namespace std;
void addEdge(vi adj[], int src, int dest)
{
	adj[src].pb(dest);
	adj[dest].pb(src);
}

void DFS(vi adj[], int u, vi &disc, vi &low, vi &parent)
{
	static int time=0;
	disc[u]=low[u]=time;
	time++;
	
	for(int v: adj[u])
	{
		if(disc[v]==-1)
		{
			parent[v]=u;
			DFS(adj, v, disc, low, parent);
			
			low[u]=min(low[u], low[v]);
			
			if(low[v]>disc[u])
			cout<<u<<" "<<v<<endl;
		}
		else if(v!=parent[u])
		low[u]=min(low[u], disc[v]);
	}
}

void bridge_Tarjans(int v, vi adj[])
{
	vi disc(v, -1), low(v, -1), parent(v, -1);
	
	for(int i=0; i<v; i++)
	if(disc[i]==-1)
	DFS(adj, i, disc, low, parent);
}

int main()
{
	int v=7;
	vi adj[v];
	
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 1, 6);
	addEdge(adj, 3, 5);
	addEdge(adj, 4, 5);
	
	bridge_Tarjans(v, adj);
	return 0;
}

//O(V+E)
