#include<bits/stdc++.h>
#include "unweighted_directed.h"
using namespace std;
#define vvi vector<vi> 
#define vi vector<int>


//Instead of destination if we want to find all pair paths, we simply 
//traverse the whole graph and then print the steps array 

void bfs(vvi &adj, int V, int source, int dest)
{
	vector<int> parent(V,-1), steps(V,-1);
	
	deque<int> queue;
	
	//add source
	queue.push_back(source);
	steps[source]=0;
	
	while(!queue.empty())
	{
		int curr=queue.front();
		queue.pop_front();
		
		vector<int>::iterator i;
		for(i=adj[curr].begin(); i!=adj[curr].end(); i++)
		{
			if(steps[*i]==-1) //not yet visited
			{
				parent[*i]=curr;
				steps[*i]=steps[curr]+1;
				queue.push_back(*i);
			}
			if(*i==dest)
			{
				//print path length
				cout<<"Path Length: "<<steps[dest]<<endl;
				//print path
				cout<<dest;
				int node=dest;
				while(node!=source)
				{
					node=parent[node];
					cout<<"<-"<<node;
				}
				return;
			}
		}
	}
}
		
			
int main()
{
	Graph* g= new Graph();
	vvi adj=g->adj;
	int V=g->V;
	
	int source=0;
	int dest=7;
	
	bfs(adj, V, source, dest);
	return 0;
}
	
//O(V+E)
