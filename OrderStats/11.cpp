#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define ll long long int

using namespace std;

//to compute prefix sum of input array 
vector<int> prefix_sum(vector<int>arr, int n)
{
	vector<int>pre_sum;
	pre_sum.push_back(arr[0]);
	for(int i=1;i<n;i++)
		pre_sum.push_back(pre_sum[i-1]+arr[i]);
	return pre_sum;
}

//update max_i by k maximum values from max_i and cand
void maxMerge(vector<int>&max_i, vector<int>cand)
{
	/*Here cand and max_i arrays are in decreasing order
	 * beforehand. Now, j is the index of the nexr cand 
	 * element and i is the index of next max_i element
	 * Traverse through max_i array. 
	 * If cand[j]>max_i[i] insert cand[j] at the ith
	 * position in the max_i array and remove the 
	 * minimum element of the max_i array, ie the 
	 * last element of the max_i array and increase j 
	 * by 1 , ie take the next cand element
	 */

	int k=max_i.size();
	int j=0; // pointing to first cand elem
	for(int i=0;i<k;i++)
	{
		if(cand[j]>max_i[i])
		{
			max_i.insert(max_i.begin()+i, cand[j]);
			max_i.erase(max_i.begin()+k);
			j++;
		}
	}
	cout<<"max_i array after merge:\n";
	for(int i=0;i<k;i++)
		cout<<max_i[i]<<" ";
	cout<<"\n";
}

//update min_i to contain the lowest k-1 elements in 
//increasing order, with 0 as an initial value
void insertMini(vector<int>&min_i, int pre_sum)
{
	/*Traverse the min_i array from left to right 
	 * If prefix_sum[i] is less than any element 
	 * then insert prefix_sum[i] at correct position
	 * and delete the maximum element of the min_i array
	 *  ie, the rightmost element of the array
	 */

	int k=min_i.size();
	for(int i=0;i<k;i++)
	{
		if(pre_sum<min_i[i])
		{
			min_i.insert(min_i.begin()+i, pre_sum);
			min_i.erase(min_i.begin()+k);
			break;
		}
	}
	cout<<"min_i array after merge:\n";
	for(int i=0;i<k;i++)
		cout<<min_i[i]<<" ";
	cout<<"\n--------------------------------------\n";
}

//function to calculate k maximum overlapping subarray sums
void kMaxOvSubArray(vector<int>arr, int k)
{
	int n=arr.size();
	//compute prefix sum of the input array
	vector<int>pre_sum=prefix_sum(arr, n);


	// set all elements of min_i as INT_MAX 
	// except 0th, set 0th as 0
	vector<int>min_i(k, INT_MAX);
	min_i[0]=0;


	//set all elements of max_i as INT_MIN
	vector<int>max_i(k, INT_MIN);


	//initialize the candidate array 
	vector<int>cand(k);

	//the most important loop of the algo!!
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(pre_sum[i]<0 && min_i[j]==INT_MAX)
			cand[j]=(-pre_sum[i])-min_i[j];
			else 
			cand[j]=pre_sum[i]-min_i[j];
		cout<<"i="<<i<<",j="<<j<<",cand[j]="<<cand[j]<<endl;
		}
	cout<<"\n";
	maxMerge(max_i, cand);
	insertMini(min_i, pre_sum[i]);
	cout<<"\n\n";
	}

	//elements of max_i array is the k max
	//overlapping subarray sums
	for(int ele : max_i)
		cout<<ele<<" ";
	cout<<endl;
	cout<<"----------------\n";
}

int main()
{
	vector<int> arr1={4, -8, 9, -4, 1, -8, -1, 6};
	int k1=4;
	cout<<"Original array:\n";
	for(int ele: arr1)
		cout<<ele<<" ";
	cout<<endl;
	kMaxOvSubArray(arr1,k1);
	

	vector<int>arr2={-2, -3, 4, -1, -2, 1, 5, -3};
	int k2=3;
	cout<<"Original array:\n";
	for(int ele: arr2)
		cout<<ele<<" ";
	cout<<endl;
	kMaxOvSubArray(arr2, k2);

	return 0;
}

