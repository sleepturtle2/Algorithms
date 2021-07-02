//Now, k can take a maximum value of m + n. This means that log k can be in the worst case, log(m + n). Logm + logn = log(mn) by properties of logarithms, and when m, n > 2, log(m + n) < log(mn). Thus this algorithm slightly outperforms the previous algorithm.
// element from two sorted arrays
// Time Complexity: O(log k)

#include <iostream>
using namespace std;

int kth(int arr1[], int m, int arr2[], int n, int k)
{

  if (k > (m + n) || k < 1)
    return -1;

  // let m <= n
  if (m > n)
    return kth(arr2, n, arr1, m, k);

  // Check if arr1 is empty returning
  // k-th element of arr2
  if (m == 0)
    return arr2[k - 1];

  // Check if k = 1 return minimum of
  // first two elements of both
  // arrays
  if (k == 1)
    return min(arr1[0], arr2[0]);

  // Now the divide and conquer part
  int i = min(m, k / 2), j = min(n, k / 2);

  if (arr1[i - 1] > arr2[j - 1])

    // Now we need to find only
    // k-j th element since we
    // have found out the lowest j
    return kth(arr1, m, arr2 + j, n - j, k - j);
  else

    // Now we need to find only
    // k-i th element since we
    // have found out the lowest i
    return kth(arr1 + i, m - i, arr2, n, k - i);
}

// Driver code
int main()
{
  int arr1[5] = {2, 3, 6, 7, 9};
  int arr2[4] = {1, 4, 8, 10};
  int m = sizeof(arr1) / sizeof(arr1[0]);
  int n = sizeof(arr2) / sizeof(arr2[0]);
  int k = 5;

  int ans = kth(arr1, m, arr2, n, k);

  if (ans == -1)
    cout << "Invalid query";
  else
    cout << ans;

  return 0;
}
//Time Complexity:O(log k)
