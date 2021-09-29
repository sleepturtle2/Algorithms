#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

void kMaxNonOverlapSums(int a[], int k, int n)
{
	//output max sum in each run
	for(int count=0;count<k;count++)
	{
		int start=0;
		int end, new_start=0;
		int max_here=0, max_so_far=INT_MIN;
		
		//find max sum using kadanes algorithm 
		for(int i=0;i<n;i++)
		{
			max_here+=a[i];
			if(max_so_far<max_here)
			{
				start=new_start;
				end=i; //update end index for range
				max_so_far=max_here;

			}
			if(a[i]<0)
			{
				max_here=0;
				new_start=i+1;
			}
		}
		cout<<"Max sum:"<<max_so_far<<", start:"<<start<<",end="<<end<<endl;
		max_so_far=INT_MIN, max_here=0;
		
		
		//now set max sum range to -inf and find max sum on the array again 
		for(int i=start; i<=end;i++)
			a[i]=INT_MIN;
	}
}
int main()
{
	int arr1[]={4, 1, 1, -1, -3,-5, 6, 2, -6, -2}; 
	int k1=4;
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	kMaxNonOverlapSums(arr1, k1, n1);

	return 0;
}

