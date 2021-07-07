/*
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided. There is also an attractive offer by the candy store. We can buy a single candy from the store and get at most K other candies (all are different types) for free.

Find the minimum amount of money we have to spend to buy all the N different candies.
Find the maximum amount of money we have to spend to buy all the N different candies.
In both cases, we must utilize the offer and get the maximum possible candies back. If k or more candies are available, we must take k candies for every candy purchase. If less than k candies are available, we must take all candies for a candy purchase.
Examples:

Input :
price[] = {3, 2, 1, 4}
k = 2
Output :
Min = 3, Max = 7
Explanation :
Since k is 2, if we buy one candy we can take
atmost two more for free.
So in the first case we buy the candy which
costs 1 and take candies worth 3 and 4 for
free, also you buy candy worth 2 as well.
So min cost = 1 + 2 = 3.
In the second case we buy the candy which
costs 4 and take candies worth 1 and 2 for
free, also We buy candy worth 3 as well.
So max cost = 3 + 4 = 7.
One important thing to note is, we must use the offer and get maximum candies back for every candy purchase. So if we want to minimize the money, we must buy candies at minimum cost and get candies of maximum costs for free. To maximize the money, we must do the reverse. Below is an algorithm based on this.

First Sort the price array.

For finding minimum amount :
  Start purchasing candies from starting
  and reduce k free candies from last with
  every single purchase.

For finding maximum amount :
   Start purchasing candies from the end
   and reduce k free candies from starting
   in every single purchase.*/

// C++ implementation to find the minimum
// and maximum amount
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum amount
// to buy all candies
int findMinimum(int arr[], int n, int k)
{
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    // Buy current candy
    res += arr[i];

    // And take k candies for free
    // from the last
    n = n - k;
  }
  return res;
}

// Function to find the maximum amount
// to buy all candies
int findMaximum(int arr[], int n, int k)
{
  int res = 0, index = 0;

  for (int i = n - 1; i >= index; i--)
  {
    // Buy candy with maximum amount
    res += arr[i];

    // And get k candies for free from
    // the starting
    index += k;
  }
  return res;
}

// Driver code
int main()
{
  int arr[] = {3, 2, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 2;
  sort(arr, arr + n);

  // Function call
  cout << findMinimum(arr, n, k) << " "
       << findMaximum(arr, n, k) << endl;
  return 0;
}
/*
Output
3 7
Time Complexity: O(n log n)
*/
