// /Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.

//Since we are given two sorted arrays, we can use the merging technique to get the final merged array. From this, we simply go to the k’th index.
#include <iostream>
using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k)
{
  int sorted1[m + n];
  int i = 0, j = 0, d = 0;
  while (i < m && j < n)
  {
    if (arr1[i] < arr2[j])
      sorted1[d++] = arr1[i++];
    else
      sorted1[d++] = arr2[j++];
  }
  while (i < m)
    sorted1[d++] = arr1[i++];
  while (j < n)
    sorted1[d++] = arr2[j++];
  return sorted1[k - 1];
}

// Driver Code
int main()
{
  int arr1[5] = {2, 3, 6, 7, 9};
  int arr2[4] = {1, 4, 8, 10};
  int k = 5;
  cout << kth(arr1, arr2, 5, 4, k);
  return 0;
}
/*Time Complexity: O(n)
Auxiliary Space : O(m + n) */
