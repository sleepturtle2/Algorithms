#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
	int V=6;
	int E=8;
	
	/*
	vector<vector<pair<int,int>>> adj=
	{
		{ {2,3}, {4,6}, {5,5} }, //0
		{ {4,7}, {5,8} }, //1
		{ {6,9} }, //2
		{ }, //3
		{ {5,1} }, //4
		{ }, //5
		{ } //6
	};*/

	vector<vector<pair<int,int>>> adj=
	{
		{{1,5}, {2,3}}, //0
		{{3,6},{2,2}}, //1
		{{4,4},{5,2}, {3,7}}, //2
		{{5,1},{4,-1}}, //3
		{{5,-2}}, //4
		{{}} //5
	}; 
	};
