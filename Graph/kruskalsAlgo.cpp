#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;

struct edge{
	int src=-1; 
	int dest=-1; 
	int wt=INT_MAX;
	
	bool operator < (edge &other) const
	{
		return wt<other.wt;
	}
};


struct subset{
	int parent=-1;
	int rank=0;
};

int find(vector<subset>&subsets, int vert)
{
	if(subsets[vert].parent!=vert)
	subsets[vert].parent=find(subsets, subsets[vert].parent); //path compression
	
	return subsets[vert].parent;
}

void Union_By_Rank(vector<subset>&subsets, int x, int y)
{
	int x_root=find(subsets, x);
	int y_root=find(subsets, y);
	
	if(subsets[x_root].rank<subsets[y_root].rank)
	subsets[x_root].parent=y_root;
	
	else if(subsets[x_root].rank>subsets[y_root].rank)
	subsets[y_root].parent=x_root;
	
	else //same rank, then make one as root and increment other rank by one
	{
		subsets[y_root].parent=x_root;
		subsets[x_root].rank++;
	}
}

void kruskalMST(int V, vector<edge>&E)
{
	sort(E.begin(), E.end());
	vector<edge>result;
	
	vector<subset>subsets(V);
	
	
	//create V subsets with single elements
	for(int v=0; v<V; v++)	
	{
		subsets[v].parent=v;
		subsets[v].rank=0;
	}
	
	int i=0;
	//repeat process for V-1 (edge count in MST)
	while(i<(int)E.size())
	{
		edge curr_edge=E[i++];
		
		//find parents of the vertices
		int x=find(subsets, curr_edge.src);
		int y=find(subsets, curr_edge.dest);
		
		if(x!=y) //does not make a cycle, hence add to edge list
		{
			result.push_back(curr_edge);
			Union_By_Rank(subsets, x, y); //pass parents of current edge vertices
		}
		
		//else discard current edge
	}
	
	cout<<"Edges in MST\n";
	int total_weight=0;
	
	for(edge e: result)
	{
		cout<<"("<<e.src<<","<<e.dest<<") ->"<<e.wt<<endl;
		total_weight+=e.wt;
	}
	cout<<"MST weight: "<<total_weight<<endl;
	
}

int main()
{
	int V=4;
	
	vector<edge>E;
	E.push_back({0,1,10});
	E.push_back({0,2,6});
	E.push_back({0,3,5});
	E.push_back({1,3,15});
	E.push_back({2,3,4});
	
	kruskalMST(V, E);
	return 0;
	

	return 0;
}

