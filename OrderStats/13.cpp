#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

void kSmallestElem(vector<int>&a, int k, int n)
{
	for(int count=0;count<k;count++)
	{
		int max=INT_MIN; int index=-1;
		
		//find max element from index 0 to n-count-1
		for(int i=0;i<n-count;i++)
			if(a[i]>max)
			{
				index=i;
				max=a[i];
			}
	a.push_back(max);
	a.erase(a.begin()+index);
		}

	for(int i=0;i<k;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	vector<int>a={4, 2, 6, 1, 5, 8, 7, 3};
	int n=a.size();
	int k=4;
	kSmallestElem(a, k, n);
	return 0;
}

