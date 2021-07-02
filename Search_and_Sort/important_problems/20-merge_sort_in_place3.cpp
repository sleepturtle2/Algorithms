/*Here we use the below technique:

Suppose we have a number A and we want to
convert it to a number B and there is also a
constraint that we can recover number A any
time without using other variable.To achieve
this we chose a number N which is greater
than both numbers and add B*N in A.
so A --> A+B*N

To get number B out of (A+B*N)
we divide (A+B*N) by N (A+B*N)/N = B.

To get number A out of (A+B*N)
we take modulo with N (A+B*N)%N = A.

-> In short by taking modulo
we get old number back and taking divide
we new number.
mergeSort():

Calculate mid two split the array into two halves(left sub-array and right sub-array)
Recursively call merge sort on left sub-array and right sub-array to sort them
Call merge function to merge left sub-array and right sub-array
merge():

We first find the maximum element of both sub-array and increment it one to avoid collision of 0 and maximum element during modulo operation.
The idea is to traverse both sub-arrays from starting simultaneously. One starts from l till m and another starts from m+1 till r. So, We will initialize 3 pointers say i, j, k.
i will move from l till m; j will move from m+1 till r; k will move from l till r.
Now update value a[k] by adding min(a[i],a[j])*maximum_element.
Then also update those elements which are left in both sub-arrays.
After updating all the elements divide all the elements by maximum_element so we get the updated array back.*/

#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void mergeInPlace(int a[], int l, int m, int r)
{
  // increment the maximum_element by one to avoid
  // collision of 0 and maximum element of array in modulo
  // operation
  int mx = max(a[m], a[r]) + 1;

  int i = l, j = m + 1, k = l;
  while (i <= m && j <= r && k <= r)
  {

    // recover back original element to compare
    int e1 = a[i] % mx;
    int e2 = a[j] % mx;
    if (e1 <= e2)
    {
      a[k] += (e1 * mx);
      i++;
      k++;
    }
    else
    {
      a[k] += (e2 * mx);
      j++;
      k++;
    }
  }

  // process those elements which are left in the array
  while (i <= m)
  {
    int el = a[i] % mx;
    a[k] += (el * mx);
    i++;
    k++;
  }

  while (j <= r)
  {
    int el = a[j] % mx;
    a[k] += (el * mx);
    j++;
    k++;
  }

  // finally update elements by dividing with maximum
  // element
  for (int i = l; i <= r; i++)
    a[i] /= mx;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {

    // Same as (l + r) / 2, but avoids overflow
    // for large l and r
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    mergeInPlace(arr, l, m, r);
  }
}

// Driver Code
int main()
{
  int nums[] = {12, 11, 13, 5, 6, 7};
  int nums_size = sizeof(nums) / sizeof(nums[0]);

  mergeSort(nums, 0, nums_size - 1);

  for (int i = 0; i < nums_size; i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}
/*Time Complexity: O(n log n)
Note:  Time Complexity of above approach is O(n2) because merge is O(n). Time complexity of standard merge sort is  O(n log n).*/
