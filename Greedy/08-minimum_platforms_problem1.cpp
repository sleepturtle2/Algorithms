/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays that represent the arrival and departure times of trains that stop.

Examples:

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explanation: There are at-most three trains at a time (time between 11:00 to 11:20)

Input: arr[] = {9:00, 9:40}
dep[] = {9:10, 12:00}
Output: 1
Explanation: Only one platform is needed.
*/

/*Naive Solution:



Approach: The idea is to take every interval one by one and find the number of intervals that overlap with it. Keep track of the maximum number of intervals that overlap with an interval. Finally, return the maximum value.
Algorithm:
Run two nested loops the outer loop from start to end and the inner loop from i+1 to end.
For every iteration of the outer loop find the count of intervals that intersect with the current interval.
Update the answer with the maximum count of overlap in each iteration of the outer loop.
Print the answer.*/
#include <algorithm>
#include <iostream>

using namespace std;

// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{

  // plat_needed indicates number of platforms
  // needed at a time
  int plat_needed = 1, result = 1;
  int i = 1, j = 0;

  // run a nested  loop to find overlap
  for (int i = 0; i < n; i++)
  {
    // minimum platform
    plat_needed = 1;

    for (int j = i + 1; j < n; j++)
    {
      // check for overlap
      if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
          (arr[j] >= arr[i] && arr[j] <= dep[i]))
        plat_needed++;
    }

    // update result
    result = max(result, plat_needed);
  }

  return result;
}

// Driver Code
int main()
{
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Minimum Number of Platforms Required = "
       << findPlatform(arr, dep, n);
  return 0;
  /*
  Output
Minimum Number of Platforms Required = 3
Complexity Analysis:

Time Complexity: O(n^2).
Two nested loops traverse the array, so the time complexity is O(n^2).
Space Complexity: O(1).
As no extra space is required.*/
