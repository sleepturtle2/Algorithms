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
void minHeapify(int a[], int rootIndex, int size)
{
	int leftIndex=2*rootIndex+1;
	int rightIndex=2*rootIndex+2;

	int smallest=rootIndex;

	if(leftIndex<size && a[leftIndex]<a[smallest])
		smallest=leftIndex;
	if(rightIndex<size && a[rightIndex]<a[smallest])
		smallest=rightIndex;

	if(smallest!=rootIndex)
	{
		swap(&a[rootIndex], &a[smallest]);
		minHeapify(a, smallest, size);

	}
}
void minHeap(int a[], int size)
{
	int rootIndex=(size-1)/2;
	while(rootIndex>=0)
	{
		minHeapify(a, rootIndex, size);
		rootIndex--;
	}
}
int main()

{
	int a[]={10,4,3,50,23,90};
	int size=sizeof(a)/sizeof(a[0]);
	int k=3;
	//print 3 largest elements in the array 
	
	int heap[k];
	for(int i=0;i<k;i++)
		heap[i]=a[i]; //put first k elements into the heap
	minHeap(heap, k); //we have a minHeap of first k elements
	
	

	//now, we want to have a minHeap of the k largest elements
	//so replace root with greater values
	
	for(int i=k;i<size;i++)
	{
		if(a[i]>heap[0])
		{
			heap[0]=a[i];
			minHeapify(heap,0,k);
		}
	}
	for(int i=0;i<k;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
		return 0;
}

