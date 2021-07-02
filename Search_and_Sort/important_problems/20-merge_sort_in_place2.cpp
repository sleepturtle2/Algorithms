/* The idea: We start comparing elements that are far from each other rather than adjacent. Basically we are using shell sorting to merge two sorted arrays with O(1) extra space.

mergeSort():

Calculate mid two split the array in two halves(left sub-array and right sub-array)
Recursively call merge sort on left sub-array and right sub-array to sort them
Call merge function to merge left sub-array and right sub-array
merge():

For every pass, we calculate the gap and compare the elements towards the right of the gap.
Initiate the gap with ceiling value of n/2 where n is the combined length of left and right sub-array.
Every pass, the gap reduces to the ceiling value of gap/2.
Take a pointer i to pass the array.
Swap the ith and (i+gap)th elements if (i+gap)th element is smaller than(or greater than when sorting in decreasing order) ith element.
Stop when (i+gap) reaches n.
*/
#include <bits/stdc++.h>
using namespace std;

// Calculating next gap
int nextGap(int gap)
{
  if (gap <= 1)
    return 0;

  return (int)ceil(gap / 2.0);
}

// Function for swapping
void swap(int nums[], int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

// Merging the subarrays using shell sorting
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
void inPlaceMerge(int nums[], int start,
                  int end)
{
  int gap = end - start + 1;

  for (gap = nextGap(gap);
       gap > 0; gap = nextGap(gap))
  {
    for (int i = start; i + gap <= end; i++)
    {
      int j = i + gap;
      if (nums[i] > nums[j])
        swap(nums, i, j);
    }
  }
}

// merge sort makes log n recursive calls
// and each time calls merge()
// which takes nlog n steps
// Time Complexity: O(n*log n + 2((n/2)*log(n/2)) +
// 4((n/4)*log(n/4)) +.....+ 1)
// Time Complexity: O(logn*(n*log n))
// i.e. O(n*(logn)^2)
// Space Complexity: O(1)
void mergeSort(int nums[], int s, int e)
{
  if (s == e)
    return;

  // Calculating mid to slice the
  // array in two halves
  int mid = (s + e) / 2;

  // Recursive calls to sort left
  // and right subarrays
  mergeSort(nums, s, mid);
  mergeSort(nums, mid + 1, e);

  inPlaceMerge(nums, s, e);
}

// Driver Code
int main()
{
  int nums[] = {12, 11, 13, 5, 6, 7};
  int nums_size = sizeof(nums) / sizeof(nums[0]);

  mergeSort(nums, 0, nums_size);

  for (int i = 0; i < nums_size; i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}
//Time Complexity: O(log n*nlog n)
//mergeSort method makes log n recursive calls and each time merge is called which takes n log n time to merge 2 sorted sub-arrays
