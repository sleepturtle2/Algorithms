//https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
/*
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10

*/

#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
  int res = 0;
  int msis[n];

  //initialize
  for (int i = 0; i < n; i++)
    msis[i] = arr[i];

  //lis logic applied here
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
      {
        msis[i] = msis[j] + arr[i];
        res = max(res, msis[i]);
      }

  return res;
}

int main()
{
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << maxSumIS(arr, n) << endl;
}
//o(n2)
