#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>
#include<queue>

#define ll long long int

using namespace std;

struct FreqNode{
	int val; 
	int freq;
};

class Compare{
public: bool operator()(FreqNode a, FreqNode b)
	{
		if(a.freq==b.freq)
			return (a.val<b.val);
		else
			return (a.freq<b.freq);
	}
};


void kMaxFreqNum(int a[], int n, int k)
{
	unordered_map<int,int>umap;
	for(int i=0;i<n;i++)
		umap[a[i]]++;
	priority_queue<FreqNode,vector<FreqNode>,Compare> maxh; //max heap
	for(auto it=umap.begin();it!=umap.end();it++)
		maxh.push({it->first, it->second});

	//print maxheap
	while(k--)
	{
		cout<<"Element:"<<maxh.top().val<<",Freq:"<<maxh.top().freq<<endl;
		maxh.pop();
	}
}

int main()
{
	int a[]={3,1,4,4,5,2,6,1};
	int n=sizeof(a)/sizeof(a[0]);
	int k=4;
	kMaxFreqNum(a, n, k);
	return 0;
}

