#include <bits/stdc++.h>
using namespace std;

int recursion(int arr[], int i, int n, int prev)
{

  //base case : nothing is remaining
  if (i == n)
    return 0;

  //case 1: exclude the current element and process the remaining elements
  int excl = recursion(arr, i + 1, n, prev);

  //case 2: include the current element if it is greater than the previous element in LIS
  int incl = 0;
  if (arr[i] > prev)
    incl = 1 + recursion(arr, i + 1, n, arr[i]);

  return max(incl, excl);
}

int tabulation(int arr[], int n)
{

  //LIS[i] stores the length of the longest increasing subsequence that ends with arr[i]
  vector<int> LIS(n);

  int max_len = INT_MIN; //to store the max value of LIS

  //LIS ending at arr[0] is 1
  LIS[0] = 1;

  //start from second array element
  for (int i = 1; i < n; i++)
  {

    for (int j = 0; j < i; j++)
    {
      //find LIS that ends with arr[j]
      //where arr[j] is less than the current element arr[i]
      if (arr[j] < arr[i] && LIS[j] > LIS[i])
        LIS[i] = LIS[j];
    }
    //include arr[i] in LIS
    LIS[i]++;

    max_len = max(max_len, LIS[i]);
  }
  return max_len;
}

int tabulation_optimized(int arr[], int n)
{

  int lis[n];
  lis[0] = 1;

  int max_len = INT_MIN;
  for (int i = 1; i < n; i++)
  {

    lis[i] = 1;
    for (int j = 0; j < i; j++)
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
      {
        lis[i] = lis[j] + 1;
        max_len = max(max_len, lis[i]);
      }
  }
  return max_len;
}

int main()
{
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << recursion(arr, 0, n, INT_MIN) << endl;

  cout << tabulation(arr, n) << endl;

  cout << tabulation_optimized(arr, n) << endl;
}
