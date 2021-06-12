#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
const int INF=1e7;

using namespace std;

struct edge
{
	int weight=INF, to=-1;
	
	bool operator<(edge const& other) const //operator overloading is compulsory for use in pq or set 
	{
		return mp(weight, to)< mp(other.weight, other.to);
	}
};

void addEdge(vector<edge>adj[], int u, int v, int wt)
{
	adj[u].pb({wt,v});
	adj[v].pb({wt,u});
}

void primsAlgo(vector<edge>adj[], int n)
{
	int total_weight=0;
	vector<edge>min_e(n); //stores (weight,from) pair
	min_e[0].weight=0;
	set<edge>q; //stores (weight,to) pair 
	q.insert({0,0});
	vector<bool>selected(n,false);
	
	for(int i=0; i<n; i++)
	{
		if(q.empty())
		{
			cout<<"No MST\n";
			exit(0);
		}
		
		int v=q.begin()->to;
		selected[v]=true;
		total_weight+=q.begin()->weight;
		q.erase(q.begin());
		
		if(min_e[v].to!=-1)
		cout<<"->"<<v<<" "<<min_e[v].to<<endl;
		
		for(edge e : adj[v])
		{
			if(!selected[e.to] && e.weight<min_e[e.to].weight)
			{
				q.erase({min_e[e.to].weight, e.to}); 
				/*
				 * When erase is called on a set (or multiset) with a key as parameter,
it returns the number of elements (with the same key) removed. If the
key is not present in the set, 0 is returned indicating that no
element was removed.
				 */
				min_e[e.to]={e.weight,v};
				q.insert({e.weight, e.to});
			}
		}
	}
	cout<<total_weight<<endl;
}
		


int main()
{
	int n=4; //no of vertices
	//int m=5; //no of edges
	
	vector<edge> adj[n]; //adjacency list of weighted edges
	
	//m edges
	addEdge(adj, 0, 1, 5);
	addEdge(adj, 0, 2, 8);
	addEdge(adj, 2, 1, 10);
	addEdge(adj, 1, 3, 15);
	addEdge(adj, 2, 3, 20);
	
	primsAlgo(adj, n);
}
