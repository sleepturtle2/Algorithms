#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define ll long long int

using namespace std;
void streamMedian(vector<double>&a)
{
	priority_queue<double>maxh; //max heap
	priority_queue<double, vector<double>, greater<double>>minh; //min heap

	// for the first element only
	maxh.push(a[0]);
	cout<<a[0]<<" ";
	
	for(int i=1;i<a.size();i++)
	{
		int curr=a[i];
		
		
		if(curr>maxh.top()) //insert in larger half if greater than root of max heap
			minh.push(curr);
		else // curr is <= maxh.top (equality for non distinct elements)
			maxh.push(curr);	// insert in smaller half if less or equal to root of max heap

		//run this part if sizes differ by more than 2 
		if(abs((int)maxh.size()-(int)minh.size())>=2) // will be =2 if true. never greater
		{
			//if max heap is larger
			if(maxh.size()>minh.size())
			{
				minh.push(maxh.top());
				maxh.pop();
			}
			//if min heap is larger
			else
			{
				maxh.push(minh.top());
				minh.pop();
			}
		}

		//here sizes are equal or any one greater than one 
		
		//even size if max heap and min heap of equal size
		if(maxh.size()==minh.size())
		cout<<(maxh.top()+minh.top())/2<<" ";


		else 	//odd size if max and min heap of different sizes
		{
			//if max heap is of greater size
			if(maxh.size()>minh.size())
				cout<<maxh.top()<<" ";
			else  		//min heap of greater size
				cout<<minh.top()<<" ";
		}
	}
	cout<<endl;

}
int main()
{
	vector<double> a={2,10,3,5,1,4};
	streamMedian(a);

	return 0;
}

