

#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
class Graph
{

public:
	vector<vector<pair<int, int>>> adj = {
			{mp(1, 3), mp(3, 7), mp(4, 8)}, //0
			{mp(3, 4), mp(2, 1)},						//1
			{},															//2
			{mp(2, 2)},											//3
			{mp(3, 3)},											//4

	};

	vector<vector<pair<int, int>>> adj2 = {
			{{1, 16}, {2, 13}}, //0
			{{2, 10}, {3, 12}}, //1
			{{1, 4}, {4, 14}},	//2
			{{2, 9}, {5, 20}},	//3
			{{3, 7}, {5, 4}},		//4
			{}									//5
	};
};
