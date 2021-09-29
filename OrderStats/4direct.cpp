#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

int main()
{
	int a[]={10,4,3,50,23,90};
	int first,second,third;
	first=second=third=INT_MIN;
	int size=sizeof(a)/sizeof(a[0]);

	for(int i=0;i<size;i++)
	{
		if(a[i]>first)
		{
			third=second;
			second=first;
			first=a[i];
		}
		else if(a[i]>second)
		{
			third=second;
			second=a[i];
		}
		else if(a[i]>third)
		{
			third=a[i];
		}
	}
	cout<<"First:"<<first<<" ,Second:"<<second<<" ,Third:"<<third<<endl;

	return 0;
}

