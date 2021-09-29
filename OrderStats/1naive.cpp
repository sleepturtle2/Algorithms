//O(NlongN)

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

int main()
{
	vector<int>v={7,10,4,3,20,15};
	int k=3,n=v.size();
	sort(v.begin(),v.end());
	cout<<v[n-k]<<endl;
	return 0;
}

