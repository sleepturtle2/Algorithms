#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;


//swap utility function
void swap( int *a, int *b )
{
	int temp=*a; //dereferenced of a
	*a=*b; // the dereferenced value of a now stores the dereferenced value of b
	*b=temp; // the dereferenced value of b now stores temp
}
class maxHeap{
	public: int *heap; //pointer to the heap array
	public: int heap_size;
public: maxHeap(int a[], int size);
	void maxHeapify(int root);
	void extractMax();
	int parent(int i){ return (i-1)/2; }
	int left(int i) { return 2*i+1; }
	int right(int i) { return 2*i +2; }
	int getMax(){ return heap[0]; }
	void replaceElem(int a, int x);
};

maxHeap:: maxHeap(int a[], int size)
{
	heap_size=size; heap=a;
	
	//get parent of the last leaf node
	int root = parent(heap_size);

	while(root>=0)
	{
		maxHeapify(root);
		root--;
	}

}

void maxHeap::maxHeapify(int root)
{
	int l=left(root); int r=right(root);
	int greatest=root; //this element stores the index of the greatest of the 3 elems out of root, left, right

	if(l<heap_size && heap[l]>heap[greatest])
		greatest=l;
	if(r<heap_size && heap[r]>heap[greatest])
		greatest=r;

	if(greatest!=root) //one of the leaf nodes if greatest, swap greatest and root
	{
		swap(&heap[root],&heap[greatest]);
		maxHeapify(greatest); //greatest now stores the root index value. hence maxHeapify the tree as well
	}
}


void maxHeap::replaceElem(int a, int x)
{
	//linear search for the element a and replace with x
	for(int i=0;i<heap_size;i++)
		if(heap[i]==a)
			heap[i]=x;
	int root=parent(heap_size);
	while(root>=0)
	{
		maxHeapify(root);
		root--;
	}
}
void slidingWindowMax(int a[], int k, int n)
{

	maxHeap maxh(a,k); //creates a minheap of the first k elements

	cout<<maxh.getMax()<<" ";
	
	
	int replace, substitute;
	for(int i=k;i<n;i++)
	{	replace=a[i-k];
		substitute=a[i];
		maxh.replaceElem(replace, substitute);
		cout<<maxh.getMax()<<" ";
		
	}
	cout<<"\n";
	
	
}

int main()
{
	int a[]={12,1,78,90,57,89,56};
	int k=3; int n=sizeof(a)/sizeof(a[0]);
	slidingWindowMax(a,k,n);
	return 0;
}

