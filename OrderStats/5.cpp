#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[], int low, int high)
{
	int n=high-low+1;
	int pivotIndex=low+rand()%n;
	int pivot=a[pivotIndex];
	
	swap(&a[high], &a[pivotIndex]);
	int SWI=low-1;
	for(int GWI=low;GWI<high;GWI++)
	{
		if(a[GWI]<pivot)
		{
			SWI++;
			swap(&a[GWI],&a[SWI]);
		}

	}
	SWI++;
	swap(&a[SWI], &a[high]);
	return SWI;
}

int partitionUtil(int a[], int low, int high, int size)
{
	int pi=partition(a, low, high);
	
	if(pi<size-3)
	return partitionUtil(a, pi+1, high, size);
	else if (pi>size-3)
		return partitionUtil(a, low, pi-1, size);
	else
		return pi;
}
void partitionMethod(int a[], int low, int high, int size)
{
	int partitionIndex=partitionUtil(a, low, high, size);
	//cout<<partitionIndex<<endl;
	for(int i=0;i<=partitionIndex;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void twoVariable(int a[], int size)
{
	int first, second;
	first=second=INT_MIN;

}
int main()
{
	int a[]={7,-2,3,4,9,-1};
	int size=sizeof(a)/sizeof(a[0]);
	partitionMethod(a, 0, size-1, size);
	twoVariable(a, size);
	return 0;
}
