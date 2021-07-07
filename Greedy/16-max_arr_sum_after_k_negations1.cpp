/*Given an array of size n and a number k. We must modify array K number of times. Here modify array means in each operation we can replace any array element arr[i] by -arr[i]. We need to perform this operation in such a way that after K operations, sum of array must be maximum?
Examples :

Input : arr[] = {-2, 0, 5, -1, 2}
        K = 4
Output: 10
Explanation:
1. Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}
2. Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}
3. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
4. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}

Input : arr[] = {9, 8, 8, 5}
        K = 3
Output: 20
This problem has very simple solution, we just have to replace the minimum element arr[i] in array by -arr[i] for current operation. In this way we can make sum of array maximum after K operations. One interesting case is, once the minimum element becomes 0, we don’t need to make any more changes.

*/

#include <bits/stdc++.h>
using namespace std;

// This function does k operations on array
// in a way that maximize the array sum.
// index --> stores the index of current minimum
// element for j'th operation
int maximumSum(int arr[], int n, int k)
{
  // Modify array K number of times
  for (int i = 1; i <= k; i++)
  {
    int min = INT_MAX;
    int index = -1;

    // Find minimum element in array for
    // current operation and modify it
    // i.e; arr[j] --> -arr[j]
    for (int j = 0; j < n; j++)
    {
      if (arr[j] < min)
      {
        min = arr[j];
        index = j;
      }
    }

    // this the condition if we find 0 as
    // minimum element, so it will useless to
    // replace 0 by -(0) for remaining operations
    if (min == 0)
      break;

    // Modify element of array
    arr[index] = -arr[index];
  }

  // Calculate sum of array
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}

// Driver code
int main()
{
  int arr[] = {-2, 0, 5, -1, 2};
  int k = 4;
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maximumSum(arr, n, k);
  return 0;
}
/*
Output
10
Time Complexity: O(k*n)
Auxiliary Space: O(1)
*/
