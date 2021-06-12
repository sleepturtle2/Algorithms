#include<vector>
using namespace std;
#define pb push_back
#define mp make_pair

struct edge
{
	int u; //source 
	int v; //destination
	int weight; //weight
};
	

class Graph
{
	
	public:

	int V=5;
	int E=9;
	vector<vector<pair<int,int>>>adj={
		{mp(1,3),mp(2,8),mp(4,-4)}, //0
		{mp(4,7),mp(3,1)}, //1
		{mp(1,4)}, //2
		{mp(0,2),mp(2,-5)}, //3
		{mp(3,6)}, //4
	};
	
	vector<edge>e=
	{
		{0,1,3},
		{0,2,8},
		{0,4,-5},
		{1,4,7},
		{1,3,1},
		{2,1,4},
		{3,0,2},
		{3,2,-5},
		{4,3,6}
	};
		 
};


