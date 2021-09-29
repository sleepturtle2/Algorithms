#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;
int kthSmallest(int arr[], int low, int high, int k, int n)
{

	set<int>set(arr, arr+n); // O(NlogN)
	auto it=set.begin();
	int ans;
	for(int i=1;i<=k;i++) //O(K)
	{
		ans=*it;
		it++;
	}
	return ans;
}
int main()
{
	int arr[]={7, 10, 4, 3, 20, 15};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	cout<<kthSmallest(arr, 0, n-1, k, n)<<endl;
	return 0;
}

