#include<bits/stdc++.h>
using namespace std;

int maxDiff(int a[], int n)
{
	int diff[n-1];
	for(int i=0;i<n-1;i++)
		diff[i]=a[i+1]-a[i];
	
	int max_diff=diff[0];
	for(int i=1;i<n-1;i++)
	{
		if(diff[i-1]>0)
			diff[i]+=diff[i-1];
		if(max_diff<diff[i])
			max_diff=diff[i];
	}
	return max_diff;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<maxDiff(a,n)<<endl;
	}
	return 0;
}
