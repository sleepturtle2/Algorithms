//https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

/*
Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
This problem is mainly an extension of below problem.
Maximum sum such that no two elements are adjacent
We maintain an auxiliary array sum[] (of same size as input array) to find the result.

sum[i] : Stores result for subarray arr[0..i], i.e.,
         maximum possible sum in subarray arr[0..i]
         such that no three elements are consecutive.

sum[0] = arr[0]

// Note : All elements are positive
sum[1] = arr[0] + arr[1]

// We have three cases
// 1) Exclude arr[2], i.e., sum[2] = sum[1]
// 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2]
sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general,
// We have three cases
// 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
sum[i] = max(sum[i-1], sum[i-2] + arr[i],
             sum[i-3] + arr[i] + arr[i-1])
*/
// C++ program to find the maximum sum such that
// no three are consecutive
#include <bits/stdc++.h>
using namespace std;

// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSumWO3Consec(int arr[], int n)
{
  // Stores result for subarray arr[0..i], i.e.,
  // maximum possible sum in subarray arr[0..i]
  // such that no three elements are consecutive.
  int sum[n];

  // Base cases (process first three elements)
  if (n >= 1)
    sum[0] = arr[0];

  if (n >= 2)
    sum[1] = arr[0] + arr[1];

  if (n > 2)
    sum[2] = max(sum[1], max(arr[1] +
                                 arr[2],
                             arr[0] + arr[2]));

  // Process rest of the elements
  // We have three cases
  // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
  // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
  // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
  for (int i = 3; i < n; i++)
    sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]),
                 arr[i] + arr[i - 1] + sum[i - 3]);

  return sum[n - 1];
}

int maxSumWO3Consec_rec(int arr[], vector<int> &sum, int n)
{
  if (sum[n] != -1)
    return sum[n];

  //Base cases (process first three elements)

  if (n == 0)
    return sum[n] = 0;

  if (n == 1)
    return sum[n] = arr[0];

  if (n == 2)
    return sum[n] = arr[1] + arr[0];

  // Process rest of the elements
  // We have three cases
  return sum[n] = max(max(maxSumWO3Consec_rec(arr, sum, n - 1),
                          maxSumWO3Consec_rec(arr, sum, n - 2) + arr[n]),
                      arr[n] + arr[n - 1] + maxSumWO3Consec_rec(arr, sum, n - 3));
}

// Driver code
int main()
{
  int arr[] = {100, 1000};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maxSumWO3Consec(arr, n) << endl;

  vector<int> sum(n + 1, -1);
  cout << maxSumWO3Consec_rec(arr, sum, n) << endl;
  return 0;
}
