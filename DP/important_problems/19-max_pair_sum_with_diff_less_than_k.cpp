//https://www.geeksforgeeks.org/maximum-sum-pairs-specific-difference/
/*
Given an array of integers and a number k. We can pair two numbers of the array if the difference between them is strictly less than k. The task is to find the maximum possible sum of disjoint pairs. Sum of P pairs is the sum of all 2P numbers of pairs.
Input  : arr[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
Output : 62
Explanation:
Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17)
So maximum sum which we can get is 3 + 5 + 12 + 10 + 15 + 17 = 62
Note that an alternate way to form disjoint pairs is, (3, 5), (9, 12), (15, 17), but this pairing produces lesser sum.
*/

// C++ program to find maximum pair sum whose
// difference is less than K
#include <bits/stdc++.h>
using namespace std;

// method to return maximum sum we can get by
// finding less than K difference pair
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
  // Sort input array in ascending order.
  sort(arr, arr + N);

  // dp[i] denotes the maximum disjoint pair sum
  // we can achieve using first i elements
  int dp[N];

  //  if no element then dp value will be 0
  dp[0] = 0;

  for (int i = 1; i < N; i++)
  {
    // first give previous value to dp[i] i.e.
    // no pairing with (i-1)th element
    dp[i] = dp[i - 1];

    // if current and previous element can form a pair
    if (arr[i] - arr[i - 1] < K)
    {
      // update dp[i] by choosing maximum between
      // pairing and not pairing
      if (i >= 2)
        dp[i] = max(dp[i], dp[i - 2] + arr[i] + arr[i - 1]);
      else
        dp[i] = max(dp[i], arr[i] + arr[i - 1]);
    }
  }

  //  last index will have the result
  return dp[N - 1];
}

//  Driver code to test above methods
int main()
{
  int arr[] = {3, 5, 10, 15, 17, 12, 9};
  int N = sizeof(arr) / sizeof(int);

  int K = 4;
  cout << maxSumPairWithDifferenceLessThanK(arr, N, K) << endl;
  return 0;
}
/*
Time complexity: O(N Log N)
Auxiliary Space: O(N)
*/
