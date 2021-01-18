#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
	int V=6;
	int E=8;
	
	vector<vector<pair<int,int>>> adj=
	{
		{ {1,3}, {2,1} }, //0
		{ {2,2}, {4,6}, {3,3} }, //1
		{ {4,2} }, //2
		{ }, //3
		{ {5,1} }, //4
		{ {3,1} } //5
	};
	};
