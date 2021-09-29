#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>

#define ll long long int
#define PI pair<int, int>
#define MP(a,b) make_pair(a,b)
using namespace std;

struct SUM{
	int sum;
	int first; //index of element in first array 
	int second; // index in second array 
};

class Compare
{
	public:	bool operator()(SUM a, SUM b)
	{
		return a.sum>b.sum;
	}
};


void KLargestSums(int a[], int b[], int size, int k)
{
	sort(a, a+size); //O(n1logn1)
	sort(b, b+size); //O(n2logn2)
	
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<size;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	set<PI>set; // store indices of sums 
	priority_queue<SUM,vector<SUM>, Compare> maxh; // max heap for two largest sums for each loop run
	
	SUM curr={a[size-1]+b[size-1], size-1, size-1};
	maxh.push(curr);
	set.insert(MP(curr.first, curr.second));

	//iterate upto count k 
	for(int count=0;count<k;count++)
	{
		curr=maxh.top();
		maxh.pop();

		cout<<"Sum:"<<curr.sum<<",index1:"<<curr.first+1<<",index2:"<<curr.second+1<<endl;

		int i=curr.first; 
		int j=curr.second;

		int sum=a[i-1]+b[j];
		PI temp=MP(i-1, j);

		if(set.find(temp)==set.end())
		{
			maxh.push({sum, i-1, j});
			set.insert(temp);
		}

		sum=a[i]+b[j-1];
		temp=MP(i,j-1);

		if(set.find(temp)==set.end())
		{
			maxh.push({sum, i, j-1});
			set.insert(temp);
		}
	}
	
		

}

int main()
{
	int a[]={4, 2, 5, 1};
	int b[]={8,0,3,5};

	int size=sizeof(a)/sizeof(a[0]); // both arrays of same size

	int k=4; // display k maxmimum possible sums and their indices 

	KLargestSums(a, b, size, k);
	return 0;
}

