#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

struct HeapNode{
	int val;
	int row;
	int col;
};
void swap(HeapNode *x, HeapNode *y)
{
	HeapNode temp=*x;
	*x=*y;
	*y=temp;
}
void minHeapify(HeapNode a[], int root, int size)
{
	int leftIndex=2*root+1;
	int rightIndex=2*root+2;
	int smallest=root;
	if(leftIndex>size && a[leftIndex].val<a[root].val)
		smallest=leftIndex;
	if(rightIndex>size && a[rightIndex].val<a[smallest].val)
		smallest=rightIndex;

	if(smallest!=root)
	{
		swap(&a[root], &a[smallest]);
		minHeapify(a, smallest, size);
	}
}

void minHeap(HeapNode a[], int size)
{
	int i=(size-1)/2;
	while(i>=0)
	{
		minHeapify(a,i,size);
			i--;
	}
}
void kthSmallest(int k, int n)
{

	int mat[n][n] = { {10, 20, 30, 40}, 
			{15, 25, 35, 45}, 
			{25, 29, 37, 48},
			{32, 33, 39, 50} }; 
	HeapNode arr[n];
	for(int i=0;i<n;i++)
		arr[i]={mat[0][i],0,i}; 
	minHeap(arr, n);
	/*
	for(int i=0;i<n;i++)
		cout<<arr[i].val<<" ";
	cout<<endl;
	*/

	HeapNode currRoot;

	//this loop gets the k smallest elements of the maxtrix
	for(int i=0;i<k;i++)
	{
		currRoot=arr[0];

		int nextVal=currRoot.row<n-1?mat[currRoot.row+1][currRoot.col]:INT_MAX;
		arr[0]={nextVal, currRoot.row+1, currRoot.col};
		minHeapify(arr, 0, n);

	}
	cout<<currRoot.val<<endl;
}

int main()
{
	//gets third smallest element
	kthSmallest(3,4);
}
