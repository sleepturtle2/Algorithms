#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

int firstMissing(int a[], int start, int end)
{
	if(start>end)
		return end+1;
	if(start!=a[start])
		return start;
	int mid=(start+end)/2;
	if(a[mid]==mid)
		return firstMissing(a,mid+1,end);
	return firstMissing(a,start,mid);
}
	

int main()
{
	int a[]={0, 1, 2, 3, 4, 5, 6, 7, 10};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<firstMissing(a, 0, n-1)<<endl;
	return 0;
}

