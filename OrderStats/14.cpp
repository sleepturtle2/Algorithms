#include<queue>
#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;
struct SUM{
	int val;
	int first; // index from first array
	int second; // index from second array
};

class Compare{
	public: bool operator()(SUM a, SUM b)
		{
			return a.val>b.val;
		}
};


void kSmallestSums(int a[], int n1, int b[], int n2, int k)
{
	if(k>n1*n2)
	{
		cout<<"Enter k within range\n";
		return;
	}


	priority_queue<SUM, vector<SUM>, Compare> minh; //min heap to print the minimum value every time 
	set<pair<int,int>>set;

	minh.push({a[0]+b[0], 0, 0});
	set.insert(make_pair(0,0));

	while(k--)
	{
		SUM curr=minh.top();
		cout<<"Sum: "<<curr.val<<" ,First index:"<<curr.first<<" ,Second index:"<<curr.second<<endl;
		
		int i=curr.first;
		int j=curr.second;
		minh.pop();

		int sum1=a[i]+b[j+1];

		//check if these indices have already been visited
		if(set.find(make_pair(i,j+1))==set.end()) //not present
		minh.push({sum1,i,j+1});

		int sum2=a[i+1]+b[j];
		//check if these indices have already been visited
		if(set.find(make_pair(i+1,j))==set.end()) //not present
		minh.push({sum2,i+1,j});

	}
	
	

}
/*
void printheap(auto minh)
{
	while(minh.size()>0)
	{
		cout<<minh.top().val<<" ";
		minh.pop();
	}
	cout<<"\n";
}
*/
int main()
{
	int a1[]={1,7,11};
	int a2[]={2,4,6,8};
	int n1=sizeof(a1)/sizeof(a1[0]);
	int n2=sizeof(a2)/sizeof(a2[0]);


	int k=3; // print 3 smallest sum with indices
	kSmallestSums(a1, n1, a2, n2, k);
	
	return 0;
}

