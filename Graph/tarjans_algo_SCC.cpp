#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define vb vector<bool>

void DFS(vi adj[], int u, vi &disc, vi &low, stack<int>&stack, vb &presentInStack)
{
	static int time = 0;
	disc[u]=low[u]=time;
	time++;
	stack.push(u);
	presentInStack[u]=true;
	
	for(int v : adj[u])
	{
		if(disc[v]==-1)
		{
			DFS(adj, v, disc, low, stack, presentInStack);
			low[u]=min(low[u], low[v]);
		}
		//Differentiate between back-edge and cross edge
		else if(presentInStack[v]) //Back-edge case 
		low[u]=min(low[u], disc[v]);
	}
	
	if(low[u]==disc[u]) //u is head node of SCC
	{
		cout<<"SCC is:\n";
		while(stack.top()!=u)
		{
			cout<<stack.top()<<" ";
			presentInStack[stack.top()]=false;
			stack.pop();
		}
		cout<<stack.top()<<"\n"; //print u 
		presentInStack[stack.top()]=false;
		stack.pop();
	}
}

void findSCC_Tarjan(int v, vector<int>adj[])
{
	vi disc(v,-1), low(v,-1);
	vb presentInStack(v, false);
	stack<int>stack;
	
	for(int i=0; i<v; i++)
	if(disc[i]==-1)
	DFS(adj, i, disc, low, stack, presentInStack);
}

void addEdge(vector<int>adj[], int src, int dest)
{
	adj[src].pb(dest);
}
int main()
{
	int v=11;
	vector<int>adj[v];
	
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 3);addEdge(adj, 1, 2);addEdge(adj, 1, 4);
	addEdge(adj, 2, 0);addEdge(adj, 2, 6);addEdge(adj, 3, 2);
	addEdge(adj, 4, 5);addEdge(adj, 4, 6);addEdge(adj, 5, 6);
	addEdge(adj, 5, 7);addEdge(adj, 5, 8);addEdge(adj, 5, 9);
	addEdge(adj, 6, 4);addEdge(adj, 7, 9);addEdge(adj, 8, 9);
	addEdge(adj, 9, 8);
	
	findSCC_Tarjan(v, adj);
	return 0;
}

	
//O(V+E)	
