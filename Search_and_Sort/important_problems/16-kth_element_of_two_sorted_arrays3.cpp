/*Divide And Conquer Approach 1
While the previous method works, can we make our algorithm more efficient? The answer is yes. By using a divide and conquer approach, similar to the one used in binary search, we can attempt to find the k’th element in a more efficient way.
Compare the middle elements of arrays arr1 and arr2, let us call these indices mid1 and mid2 respectively. Let us assume arr1[mid1]  k, then clearly the elements after mid2 cannot be the required element. Set the last element of arr2 to be arr2[mid2].
In this way, define a new subproblem with half the size of one of the arrays.*/

#include <iostream>
using namespace std;

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
  if (arr1 == end1)
    return arr2[k];
  if (arr2 == end2)
    return arr1[k];
  int mid1 = (end1 - arr1) / 2;
  int mid2 = (end2 - arr2) / 2;
  if (mid1 + mid2 < k)
  {
    if (arr1[mid1] > arr2[mid2])
      return kth(arr1, arr2 + mid2 + 1, end1, end2,
                 k - mid2 - 1);
    else
      return kth(arr1 + mid1 + 1, arr2, end1, end2,
                 k - mid1 - 1);
  }
  else
  {
    if (arr1[mid1] > arr2[mid2])
      return kth(arr1, arr2, arr1 + mid1, end2, k);
    else
      return kth(arr1, arr2, end1, arr2 + mid2, k);
  }
}

int main()
{
  int arr1[5] = {2, 3, 6, 7, 9};
  int arr2[4] = {1, 4, 8, 10};

  int k = 5;
  cout << kth(arr1, arr2, arr1 + 5, arr2 + 4, k - 1);
  return 0;
}
/*Note that in the above code, k is 0 indexed, which means if we want a k that’s 1 indexed, we have to subtract 1 when passing it to the function.
Time Complexity: O(log n + log m)
*/
