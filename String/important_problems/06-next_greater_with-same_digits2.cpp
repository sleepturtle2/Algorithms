/*
The above implementation can be optimized in following ways.
1) We can use binary search in step II instead of linear search.
2) In step IV, instead of doing simple sort, we can apply some clever technique to do it in linear time. Hint: We know that all digits are linearly sorted in reverse order except one digit which was swapped.
With above optimizations, we can say that the time complexity of this method is O(n).

Optimised Approach :

1. Here instead of sorting the digits after (i-1) index, we are reversing the digits as mentioned in the above optimisation point.
2. As they will be in decreasing order so to find the smallest element possible from the right part we just reverse them thus reducing time complexity.

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int n, vector<int> arr)
{
  // If number of digits is 1 then just return the vector
  if (n == 1)
    return arr;

  // Start from the right most digit and find the first
  // digit that is
  // smaller than the digit next to it.
  int i = 0;
  for (i = n - 1; i > 0; i--)
  {
    if (arr[i] > arr[i - 1])
      break;
  }

  // If there is a possibility of a next greater element
  if (i != 0)
  {
    // Find the smallest digit on right side of (i-1)'th
    // digit that is
    // greater than number[i-1]
    for (int j = n - 1; j >= i; j--)
    {
      if (arr[i - 1] < arr[j])
      {
        // Swap the found smallest digit i.e. arr[j]
        // with arr[i-1]
        swap(arr[i - 1], arr[j]);
        break;
      }
    }
  }

  // Reverse the digits after (i-1) because the digits
  // after (i-1) are in decreasing order and thus we will
  // get the smallest element possible from these digits
  reverse(arr.begin() + i, arr.end());

  // If i is 0 that means elements are in decreasing order
  // Therefore, no greater element possible then we just
  // return the lowest possible
  // order/element formed from these digits by just
  // reversing the vector

  return arr;
}

int main()
{
  int n = 6;
  vector<int> v{5, 3, 4, 9, 7, 6};
  vector<int> res;
  res = nextPermutation(n, v);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}
//o(n)
