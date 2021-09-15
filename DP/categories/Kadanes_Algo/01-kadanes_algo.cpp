//practice link
//https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define pii pair<int, int>
#define mp make_pair

int maxSubSum(vector<int> &a)
{
	int n = a.size();
	int max_so_far = INT_MIN;
	int max_ending_here = 0;

	for (int i = 0; i < n; i++)
	{
		max_ending_here += a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int main()
{
	vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout << "Maximum contiguous sum is: " << maxSubSum(a) << endl;
	return 0;
}
