#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

void countSmaller(int a[], int n)
{
	set<int> set;
	int count[n];

	for(int i=n-1;i>=0;i--)
	{
		set.insert(a[i]);
		auto it=set.lower_bound(a[i]);
		count[i]=distance(set.begin(),it);

	}
	for(int i=0;i<n;i++)
		cout<<count[i]<<" ";
	cout<<endl;
}

int main()
{
	int a[]={12,1,2,3,0,11,4};
	int n=sizeof(a)/sizeof(a[0]);
	countSmaller(a,n);

	return 0;
}

