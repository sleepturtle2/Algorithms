#include <climits>
#include <iostream>
using namespace std;

// function to calculate sum between two indices
// in array
int sum(int arr[], int from, int to)
{
  int total = 0;
  for (int i = from; i <= to; i++)
    total += arr[i];
  return total;
}

// bottom up tabular dp
int findMax(int arr[], int n, int k)
{
  // initialize table
  int dp[k + 1][n + 1] = {0};

  // base cases
  // k=1
  for (int i = 1; i <= n; i++)
    dp[1][i] = sum(arr, 0, i - 1);

  // n=1
  for (int i = 1; i <= k; i++)
    dp[i][1] = arr[0];

  // 2 to k partitions
  for (int i = 2; i <= k; i++)
  { // 2 to n boards
    for (int j = 2; j <= n; j++)
    {

      // track minimum
      int best = INT_MAX;

      // i-1 th separator before position arr[p=1..j]
      for (int p = 1; p <= j; p++)
        best = min(best, max(dp[i - 1][p],
                             sum(arr, p, j - 1)));

      dp[i][j] = best;
    }
  }

  // required
  return dp[k][n];
}

// driver function
int main()
{
  int arr[] = {10, 20, 60, 50, 30, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  cout << findMax(arr, n, k) << endl;
  return 0;
}

/*
 The time complexity of the above program is O(k*N^3). It can be easily brought down to O(k*N^2) by precomputing the cumulative sums in an array thus avoiding repeated calls to the sum function:


int sum[n+1] = {0};

 // sum from 1 to i elements of arr
 for (int i = 1; i <= n; i++)
   sum[i] = sum[i-1] + arr[i-1];

 for (int i = 1; i <= n; i++)
   dp[1][i] = sum[i];

and using it to calculate the result as:
best = min(best, max(dp[i-1][p], sum[j] - sum[p]));*/

/*
Though here we consider to divide A into k or fewer partitions, we can observe that
the optimal case always occurs when we divide A into exactly k partitions. So we can use:

for (int i = k-1; i <= n; i++)
    best = min(best, max( partition(arr, i, k-1),
                            sum(arr, i, n-1)));
                            */
