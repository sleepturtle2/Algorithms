/*While the above implementation is very efficient, we can still get away with making it more efficient. Instead of dividing the array into segments of n / 2 and m / 2 then recursing, we can divide them both by k / 2 and recurse. The below implementation displays this.

Explanation:
Instead of comparing the middle element of the arrays,
we compare the k / 2nd element.
Let arr1 and arr2 be the arrays.
Now, if arr1[k / 2]  arr1[1]

New subproblem:
Array 1 - 6 7 9
Array 2 - 1 4 8 10
k = 5 - 2 = 3

floor(k / 2) = 1
arr1[1] = 6
arr2[1] = 1
arr1[1] > arr2[1]

New subproblem:
Array 1 - 6 7 9
Array 2 - 4 8 10
k = 3 - 1 = 2

floor(k / 2) = 1
arr1[1] = 6
arr2[1] = 4
arr1[1] > arr2[1]

New subproblem:
Array 1 - 6 7 9
Array 2 - 8 10
k = 2 - 1 = 1

Now, we directly compare first elements,
since k = 1.
arr1[1] < arr2[1]
Hence, arr1[1] = 6 is the answer.*/

#include <iostream>
using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k,
        int st1 = 0, int st2 = 0)
{
  // In case we have reached end of array 1
  if (st1 == m)
    return arr2[st2 + k - 1];

  // In case we have reached end of array 2
  if (st2 == n)
    return arr1[st1 + k - 1];

  // k should never reach 0 or exceed sizes
  // of arrays
  if (k == 0 || k > (m - st1) + (n - st2))
    return -1;

  // Compare first elements of arrays and return
  if (k == 1)
    return (arr1[st1] < arr2[st2]) ? arr1[st1] : arr2[st2];
  int curr = k / 2;

  // Size of array 1 is less than k / 2
  if (curr - 1 >= m - st1)
  {
    // Last element of array 1 is not kth
    // We can directly return the (k - m)th
    // element in array 2
    if (arr1[m - 1] < arr2[st2 + curr - 1])
      return arr2[st2 + (k - (m - st1) - 1)];
    else
      return kth(arr1, arr2, m, n, k - curr,
                 st1, st2 + curr);
  }

  // Size of array 2 is less than k / 2
  if (curr - 1 >= n - st2)
  {
    if (arr2[n - 1] < arr1[st1 + curr - 1])
      return arr1[st1 + (k - (n - st2) - 1)];
    else
      return kth(arr1, arr2, m, n, k - curr,
                 st1 + curr, st2);
  }
  else
  {
    // Normal comparison, move starting index
    // of one array k / 2 to the right
    if (arr1[curr + st1 - 1] < arr2[curr + st2 - 1])
      return kth(arr1, arr2, m, n, k - curr,
                 st1 + curr, st2);
    else
      return kth(arr1, arr2, m, n, k - curr,
                 st1, st2 + curr);
  }
}

// Driver code
int main()
{
  int arr1[5] = {2, 3, 6, 7, 9};
  int arr2[4] = {1, 4, 8, 10};

  int k = 5;
  cout << kth(arr1, arr2, 5, 4, k);
  return 0;
}
//Time Complexity: O(log k)
