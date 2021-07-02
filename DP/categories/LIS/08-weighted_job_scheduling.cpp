/*Given N jobs where every job is represented by following three elements of it.
1. Start Time
2. Finish Time
3. Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

We first need to sort jobs according to start time. Let job[0..n-1] be the array of jobs after sorting. We define vector L such that L[i] is itself is a vector that stores Weighted Job Scheduling of job[0..i] that ends with job[i]. Therefore for an index i, L[i] can be recursively written as –

L[0] = {job[0]}
L[i] = {MaxSum(L[j])} + job[i] where j < i and job[j].finish <= job[i].start
     = job[i], if there is no such j
     */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
  int start, finish, profit;
};

// Utility function to calculate sum of all vector
// elements
int findSum(vector<Job> arr)
{
  int sum = 0;
  for (int i = 0; i < arr.size(); i++)
    sum += arr[i].profit;
  return sum;
}

// comparator function for sort function
int compare(Job x, Job y)
{
  return x.start < y.start;
}

// The main function that finds the maximum possible
// profit from given array of jobs
void findMaxProfit(vector<Job> &arr)
{
  // Sort arr[] by start time.
  sort(arr.begin(), arr.end(), compare);

  // L[i] stores stores Weighted Job Scheduling of
  // job[0..i] that ends with job[i]
  vector<vector<Job>> L(arr.size());

  // L[0] is equal to arr[0]
  L[0].push_back(arr[0]);

  // start from index 1
  for (int i = 1; i < arr.size(); i++)
  {
    // for every j less than i
    for (int j = 0; j < i; j++)
    {
      // L[i] = {MaxSum(L[j])} + arr[i] where j < i
      // and arr[j].finish <= arr[i].start
      if ((arr[j].finish <= arr[i].start) &&
          (findSum(L[j]) > findSum(L[i])))
        L[i] = L[j];
    }
    L[i].push_back(arr[i]);
  }

  vector<Job> maxChain;

  // find one with max profit
  for (int i = 0; i < L.size(); i++)
    if (findSum(L[i]) > findSum(maxChain))
      maxChain = L[i];

  for (int i = 0; i < maxChain.size(); i++)
    cout << "(" << maxChain[i].start << ", " << maxChain[i].finish << ", "
         << maxChain[i].profit << ") ";
}

// Driver Function
int main()
{
  Job a[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
  int n = sizeof(a) / sizeof(a[0]);

  vector<Job> arr(a, a + n);

  findMaxProfit(arr);

  return 0;
}
/*
Time complexity of above Dynamic Programming solution is O(n2) where n is the number of Jobs.
Auxiliary space used by the program is O(n2).*/
