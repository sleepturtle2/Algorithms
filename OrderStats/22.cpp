#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;
int findMax(int a[], int low, int high)

{

	//only one element is present in a[low->high]
	if(low==high)
		return a[low];
	//if two elements, return greater of the two
	if(high==low+1 && a[low]>=a[high])
		return a[low];
	if(high==low+1 && a[low]<a[high])
		return a[high];

	int mid=(low+high)/2;

	if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
		return a[mid];
	if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
		return findMax(a,low,mid-1);

	else
		return findMax(a,mid+1,high);
}
int main()
{
	int a1[]={8,10,20,80,100,200,400,500,3,2,1};
	int n1=sizeof(a1)/sizeof(a1[0]);
	cout<<findMax(a1,0,n1-1)<<endl;
	return 0;
}

