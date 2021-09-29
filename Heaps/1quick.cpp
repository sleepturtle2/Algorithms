#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

//O(N)
int partition(int arr[], int low, int high)
{
	if(low<=high)
	{
		//SWI = smaller elements window end
		//GWI = greater elements window start

		int SWI=low-1; int pivot=arr[high];
		for(int GWI=low;GWI<=high-1;GWI++)
		{
			if(arr[GWI]<=pivot)
			{
				SWI++;
				swap(&arr[SWI], &arr[GWI]);
			}
		}
		SWI++;
		swap(&arr[SWI], &pivot);
		return SWI;

	}
	return -1;
}

int kthSmallest(int arr[], int low, int high, int k)
{
	int pi=partition(arr, low, high);
	//cout<<pi<<endl;
	if(pi==k-1)
		return arr[pi];
	else if(pi>k-1)
		return kthSmallest(arr, low, pi-1, k);
	else
		return kthSmallest(arr, pi+1, high, k);
}
int main()
{
	int arr[]={2,3,4,5,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	cout<<kthSmallest(arr,0,n-1,k)<<endl;
	//cout<<partition(arr, 1, 2)<<endl;
	return 0;
}

