#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;
void maxNonOverlapSum(int a[], int n)
{
	int prev_incl=a[0]; //maximum sum including the previous element
	int prev_excl=0; // maximum sum excluding the previous element 
	int curr_incl; // maximum sum including the current element 
	int curr_excl; // maximum sum excluding the current element 

	for(int i=1;i<n;i++)
	{
		curr_incl=prev_excl+a[i];
		curr_excl=max(prev_incl, prev_excl);
		prev_incl=curr_incl; prev_excl=curr_excl;
	}
	cout<<max(curr_incl, curr_excl)<<endl;
}
int main()
{
	int a[]={5,-5,10,40,-50,35};
	int n=sizeof(a)/sizeof(a[0]);
	maxNonOverlapSum(a,n);

	return 0;
}

