#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

void withMaxMinArray(int a[],int n)
{
	int minarray[n];
	int maxarray[n];

	minarray[0]=a[0];
	for(int i=1;i<n;i++)
		minarray[i]=min(minarray[i-1],a[i]);
	
	maxarray[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
		maxarray[i]=max(maxarray[i+1],a[i]);


	int i=0,j=0; int ans=-1;
	while(i<n && j<n)
	{
		if(minarray[i]<maxarray[j])
		{
			ans=max(ans,j-i); j++;
		}
		else i++;
	}
	cout<<ans<<endl;
}

void withMaxArray(int a[], int n)
{
	int maxarray[n];
	maxarray[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		maxarray[i]=max(maxarray[i+1],a[i]);
	}
	
	int res=-1, finalStart, finalEnd;
	for(int i=0;i<n-1;i++)
	{
		int low=i+1; int high=n-1; int ans=-1; int start; int end;
		while(low<=high)

		{
			int mid=(low+high)/2;
			if(maxarray[mid]>a[i])
			{
				ans=mid-i; start=i; end=mid;
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}

		}
		if(ans>res)
		{
			finalStart=start; finalEnd=end; res=ans;
		}
	}
	cout<<res<<" from index "<<finalStart<<" to "<<finalEnd<<endl;
}

void bruteForce(int a[], int n)
{
	cout<<"Brute Force method:\n";
	int maxDiff=INT_MIN;
	int start, end;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		if(a[j]>a[i] && maxDiff < j-i)
		{maxDiff=(j-i); start=i; end=j;}
	}	
	cout<<maxDiff<<", index "<<start<<" to "<<end<<endl;
}
int main()
{
	int a[]={9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n=sizeof(a)/sizeof(a[0]);

	//brute force O(N^2)
	//bruteForce(a,n);

	//creating a max array and searching for max on the right of an element ... O(NlogN)
	//withMaxArray(a,n);
	
	//creating a min array for the lowest element from curr
	//index to the beginning, ie to the left
	//
	//creating a max array for the greatest element from curr
	//index to the end, ie to the right
	withMaxMinArray(a,n); //O(N)
	return 0;
}

