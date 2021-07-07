/*
Algorithmic Paradigm: Greedy Algorithm
A simple implementation with STL in C++
This uses priority_queue available in STL. Thanks to Pango89 for providing the below code. The approach and algorithm remains the same. The min Heap is replaced by a priority Queue.
*/

#include <bits/stdc++.h>

using namespace std;

int minCost(int arr[], int n)
{
  // Create a priority queue
  // https:// www.geeksforgeeks.org/priority-queue-in-cpp-stl/
  // By default 'less' is used which is for decreasing order
  // and 'greater' is used for increasing order
  priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

  // Initialize result
  int res = 0;

  // While size of priority queue is more than 1
  while (pq.size() > 1)
  {
    // Extract shortest two ropes from pq
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    // Connect the ropes: update result and
    // insert the new rope to pq
    res += first + second;
    pq.push(first + second);
  }

  return res;
}

// Driver program to test above function
int main()
{
  int len[] = {4, 3, 2, 6};
  int size = sizeof(len) / sizeof(len[0]);
  cout << "Total cost for connecting ropes is " << minCost(len, size);
  return 0;
}
/*
Output:

Total cost for connecting ropes is 29
Complexity Analysis:

Time Complexity: O(nLogn), assuming that we use a O(nLogn) sorting algorithm.
Note that heap operations like insert and extract take O(Logn) time.
Auxiliary Complexity: O(n).
The space required to store the values in min heap
*/
