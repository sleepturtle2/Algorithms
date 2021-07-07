/*
Given an array of N integers. You are allowed to rearrange the elements of the array. The task is to find the maximum value of Σarr[i]*i, where i = 0, 1, 2,…., n – 1.

Examples:

Input : N = 4, arr[] = { 3, 5, 6, 1 }
Output : 31
If we arrange arr[] as { 1, 3, 5, 6 }.
Sum of arr[i]*i is 1*0 + 3*1 + 5*2 + 6*3
= 31, which is maximum

Input : N = 2, arr[] = { 19, 20 }
Output : 20
A simple solution is to generate all permutations of given array. For every permutation, compute the value of Σarr[i]*i and finally return the maximum value.
An efficient solution is based on the fact that the largest value should be scaled maximum and the smallest value should be scaled minimum. So we multiply the minimum value of i with the minimum value of arr[i]. So, sort the given array in increasing order and compute the sum of arr[i]*i, where i = 0 to n-1.
Below is the implementation of this approach:
*/

#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
  // Sort the array
  sort(arr, arr + n);

  // Finding the sum of arr[i]*i
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += (arr[i] * i);

  return sum;
}

// Driven Program
int main()
{
  int arr[] = {3, 5, 6, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << maxSum(arr, n) << endl;
  return 0;
}

/*
Output:

31
Time Complexity : O(n Log n)
*/
