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

int partition(int arr[], int low, int high)
{
	if(low<=high)
	{
		int n=high-low+1;
		int SWI=low-1; 
		

		//making a random number a pivot 
		int pivot=arr[low+rand()%n];
		swap(&arr[high],&pivot);

		for(int GWI=low;GWI<high;GWI++)
		{
			if(arr[GWI]<=pivot)
			{
				SWI++;
				swap(&arr[GWI], &arr[SWI]);
			}
		}
		SWI++;
		swap(&arr[SWI],&pivot);
		return SWI;
	}
	return -1;
}

int kthSmallest(int arr[], int low, int high, int k, int n)
{
	int pi=partition(arr, low, high);
	if(pi<k-1)
		return kthSmallest(arr, pi+1, high, k, n);
	else if (pi==k-1)
		return arr[pi];
	else
		return kthSmallest(arr, low, pi-1, k, n);
}

int main()
{
	int arr[]={3, 4, 5, 7, 12, 19, 26};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	//cout<<partition(arr, 2, 2)<<endl;
	cout<<kthSmallest(arr, 0, n-1, k, n)<<endl;
	return 0;
}

