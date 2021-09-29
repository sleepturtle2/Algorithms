#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define ll long long int

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;

		priority_queue<int>pq;
		
		//O(NlogN)
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			pq.push(temp);
		}

		//O(KlogN)
		for(int i=1;i<=k;i++)
		{
			cout<<pq.top()<<" ";
			pq.pop();
		}
		cout<<"\n";
	}

	return 0;
}

