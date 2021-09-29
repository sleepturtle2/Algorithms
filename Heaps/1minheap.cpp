#include<bits/stdc++.h>


#define ll long long int

using namespace std;

class minHeap{
	vector<int>heap_arr;
	//int capacity;
	int size;
public:
	minHeap(vector<int>&v,int s);
	void minHeapify(int i);
	int parent(int i){ return (i-1)/2; }
	int left(int i) { return 2*i + 1; }
	int right(int i) { return 2*i + 2; }

	int extractMin();
	int getMin(){ return heap_arr[0]; }
};

minHeap::minHeap(vector<int>&v, int s)
{
	heap_arr=v;
	size=s;
	int i=(size-1)/2;
	while(i>=0)
	{
		minHeapify(i);
		i--;
	}
}

int minHeap::extractMin()
{
	if(size==0)
		return INT_MAX;

	int root=heap_arr[0];

	if(size>1)
	{
		heap_arr[0]=heap_arr[size-1];
		minHeapify(0);
	}
	size--;
	return root;
}
//O(logN)
void minHeap::minHeapify(int i)
{
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<size && heap_arr[l]<heap_arr[i])
		smallest=l;
	if(r<size && heap_arr[r]<heap_arr[smallest])
		smallest=r;
	if(smallest!=i)
	{
		swap(heap_arr[i], heap_arr[smallest]);
		minHeapify(smallest);
	}
}

int kthSmallest(vector<int>&v, int k)
{
	//O(N)
	minHeap mh(v, v.size());
	for(int i=0;i<k-1;i++)
		cout<<mh.extractMin()<<endl; //k* O(logN)

	return mh.getMin();
}

int main()
{
	vector<int>v={30,40,20,10,70,40};
	int k=3;	
	cout<<kthSmallest(v,k)<<endl;

	return 0;
}

