/*
The idea used in above post is to replace the minimum element arr[i] in array by -arr[i] for current operation. In this way we can make sum of array maximum after K operations. Once interesting case is, once minimum element becomes 0, we don’t need to make any more changes.
The implementation used in above solution uses linear search to find minimum element. The time complexity of the above discussed solution is O(nk)
In this post an optimized solution is implemented that uses a priority queue (or binary heap) to find minimum element quickly. */
#include <bits/stdc++.h>
using namespace std;

// Function to find Maximum sum
// after K negations
int MaxSum(int a[], int n, int k)
{
  int sum = 0;

  // Create a min heap for priority queue
  priority_queue<int, vector<int>, greater<int>> pq;

  // Insert all elements in f array in priority_queue
  for (int i = 0; i < n; i++)
  {
    pq.push(a[i]);
  }

  while (k--)
  {

    // Retrieve and remove min element
    int temp = pq.top();

    pq.pop();

    // Modify the minimum element and
    // add back to priority queue
    temp = (temp) * -1;
    pq.push(temp);
  }

  // Calculate the sum
  while (!pq.empty())
  {
    sum = sum + pq.top();
    pq.pop();
  }
  return sum;
}

// Driver Code
int main()
{
  int a[] = {-2, 0, 5, -1, 2};
  int n = sizeof(a) / sizeof(a[0]);
  int k = 4;

  cout << MaxSum(a, n, k);
  return 0;
}
/*
 Output:




10
*/
