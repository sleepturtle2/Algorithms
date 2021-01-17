#include<vector>
using namespace std;
#define pb push_back

class Graph
{
	
	public:

	int V=8;
	int E=12;
	vector<vector<int>>adj={
		{1,2,3}, //0
		{0,4,5}, //1
		{0,4,5,6}, //2
		{0,6}, //3
		{1,2,7}, //4
		{1,2,7}, //5
		{2,3,7}, //6
		{4,5,6} //7
	};
		 
};

