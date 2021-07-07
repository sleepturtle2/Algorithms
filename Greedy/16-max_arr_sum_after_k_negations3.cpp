/*Approach 3(Using Sort):
The above approach 2 is optimal when there is a need to negate at most k elements. To solve when there are exactly k negations the algorithm is given below.

Sort the array in ascending order. Initialize i = 0.
Increment i and multiply all negative elements by -1 till k becomes or a positive element is reached.
Check if the end of the array has occurred. If true then go to (n-1)th element.
If k ==0 or k is even, return the sum of all elements. Else multiply the absolute of minimum of ith or (i-1) th element by -1.
Return sum of the array.*/
#include <algorithm>
#include <iostream>
using namespace std;

// Function to calculate sum of the array
long long int sumArray(long long int *arr, int n)
{
  long long int sum = 0;

  // Iterate from 0 to n - 1
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum;
}

// Function to maximize sum
long long int maximizeSum(long long int arr[], int n, int k)
{
  sort(arr, arr + n);
  int i = 0;

  // Iterate from 0 to n - 1
  for (i = 0; i < n; i++)
  {
    if (k && arr[i] < 0)
    {
      arr[i] *= -1;
      k--;
      continue;
    }
    break;
  }
  if (i == n)
    i--;

  if (k == 0 || k % 2 == 0)
  {
    return sumArray(arr, n);
  }

  if (i != 0 && abs(arr[i]) >= abs(arr[i - 1]))
  {
    i--;
  }

  arr[i] *= -1;
  return sumArray(arr, n);
}

// Driver Code
int main()
{
  int n = 5;
  int k = 4;
  long long int arr[5] = {-3, -2, -1, 5, 6};

  // Function Call
  cout << maximizeSum(arr, n, k) << endl;
  return 0;
}

/*
Output
15
Time Complexity: O(n*logn)

Auxiliary Space: O(1)
*/
