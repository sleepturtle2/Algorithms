

#include<vector>
using namespace std;
#define pb push_back
#define mp make_pair
class Graph
{
	
	public:

	int V=5;
	int E=7;
	vector<vector<pair<int,int>>>adj={
		{mp(1,3),mp(3,7),mp(4,8)}, //0
		{mp(3,4),mp(2,1)}, //1
		{}, //2
		{mp(2,2)}, //3
		{mp(3,3)}, //4
		
	};
		 
};

