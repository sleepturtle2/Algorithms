/*The simplest method is to run two loops, the outer loop picks the first element (smaller element) and the inner loop looks for the element picked by outer loop plus n. Time complexity of this method is O(n^2).
We can use sorting and Binary Search to improve time complexity to O(nLogn). The first step is to sort the array in ascending order. Once the array is sorted, traverse the array from left to right, and for each element arr[i], binary search for arr[i] + n in arr[i+1..n-1]. If the element is found, return the pair.
Both first and second steps take O(nLogn). So overall complexity is O(nLogn).
The second step of the above algorithm can be improved to O(n). The first step remain same. The idea for second step is take two index variables i and j, initialize them as 0 and 1 respectively. Now run a linear loop. If arr[j] – arr[i] is smaller than n, we need to look for greater arr[j], so increment j. If arr[j] – arr[i] is greater than n, we need to look for greater arr[i], so increment i. Thanks to Aashish Barnwal for suggesting this approach.
The following code is only for the second step of the algorithm, it assumes that the array is already sorted. */
// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;

// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
  // Initialize positions of two elements
  int i = 0;
  int j = 1;

  // Search for a pair
  while (i < size && j < size)
  {
    if (i != j && arr[j] - arr[i] == n)
    {
      cout << "Pair Found: (" << arr[i] << ", " << arr[j] << ")";
      return true;
    }
    else if (arr[j] - arr[i] < n)
      j++;
    else
      i++;
  }

  cout << "No such pair";
  return false;
}

// Driver program to test above function
int main()
{
  int arr[] = {1, 8, 30, 40, 100};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n = 60;
  findPair(arr, size, n);
  return 0;
}

// This is code is contributed by rathbhupendra
