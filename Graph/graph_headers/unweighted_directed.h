
#include<vector>
using namespace std;
#define pb push_back

class Graph
{
	
	public:


	vector<vector<int>>adj={
		{1,2,3}, //0
		{4,5}, //1
		{4,6}, //2
		{6}, //3
		{7}, //4
		{2,7}, //5
		{7}, //6
		{} //7
	};

	vector<vector<int>>adj2 = {
		{2, 3}, //0
		{0}, //1
		{1}, //2
		{4}, //3
		{}
	};	

	vector<vector<int>>adj3 = {
		{1, 3}, //0
		{2, 4}, //1
		{0, 6}, //2
		{2}, //3
		{5, 6}, //4
		{6, 7, 8, 9}, //5
		{4}, //6
		{9}, //7
		{9}, //8
		{8}, //9
		{} //10
	};

	vector<vector<int>>  adj4={
		{1}, 
		{2}, 
		{3, 4}, 
		{0}, 
		{2}

	};

};

