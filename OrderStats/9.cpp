#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define ll long long int
using namespace std;


struct minSum{
	int val;
	int start; 
	int end;
};
class Compare{
	public:
	bool operator()(minSum a, minSum b)
	{
		return a.val<b.val;
	}
};

minSum largestSum(int a[], int size, int k)
{
	// calculate cumulative sum
	int preSum[size];
	preSum[0]=a[0];
	for(int i=1;i<size;i++)
		preSum[i]=preSum[i-1]+a[i];

	minSum currSum;
	//form min heap from the first k contiguous sums
	priority_queue<minSum, vector<minSum>, Compare> minh; //min heap
		
	int left, right;
	for( left=1;left<=size;left++ )
		for( right=left; right<=size; right++ )
		{
			currSum={preSum[right]-preSum[left-1], left, right};
			//cout<<currSum.val<<endl;
			
			//continue  pushing till size of minheap is k 
			if(minh.size()<k)
				minh.push(currSum);
			else // size is equal to k here
			{
				if(currSum.val>minh.top().val)
				{
					//cout<<"CurrVal:"<<currSum.val<<" ,Top:"<<minh.top().val;
					minh.pop();
					minh.push(currSum);
				}

			}
		}
	
	
	return minh.top();
}

int main()
{

	int a[]={4,6,-7,3,-2,9,0,-1,5,8};
	int size=sizeof(a)/sizeof(a[0]);

	int k=3;
	minSum m=largestSum(a,size,k);
	cout<<"Kth Largest Sum:"<<m.val<<" ,Start:"<<m.start<<" ,End:"<<m.end<<endl;
	return 0;
}

