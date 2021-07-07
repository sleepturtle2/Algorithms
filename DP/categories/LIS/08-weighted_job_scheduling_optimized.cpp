// C++ program for weighted job scheduling using Dynamic Programming
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
  int start, finish, profit;
};

// The main function that finds the maximum possible
// profit from given array of jobs
void findMaxProfit(vector<Job> arr)
{
  // L[i] stores stores Weighted Job Scheduling of
  // job[0..i] that ends with job[i]
  vector<vector<Job>> L(arr.size());
  vector<int> sum(arr.size(), 0);

  // L[0] is equal to arr[0]
  L[0].push_back(arr[0]);
  sum[0] = arr[0].profit;

  // start from index 1
  for (int i = 1; i < arr.size(); i++)
  {
    // for every j less than i
    for (int j = 0; j < i; j++)
    {
      // L[i] = {MaxSum(L[j])} + arr[i] where j < i
      // and arr[j].finish <= arr[i].start
      if ((arr[j].finish <= arr[i].start) && (sum[j] > sum[i]))
      {
        L[i] = L[j];
        sum[i] = arr[j].profit;
      }
    }
    L[i].push_back(arr[i]);
    sum[i] += arr[i].profit;
  }
  // int k = 0;
  // for (vector<Job> i : L)
  // {
  //   cout << k++ << ": " << endl;
  //   for (Job j : i)
  //     cout << j.start << " " << j.finish << " " << j.profit << endl;
  // }
  vector<Job> maxChain;
  int max = 0;
  // find one with max profit
  for (int i = 0; i < L.size(); i++)
    if (sum[i] > max)
    {
      max = sum[i];
      maxChain = L[i];
    }

  for (int i = 0; i < maxChain.size(); i++)
    cout << "(" << maxChain[i].start << ", " << maxChain[i].finish << ", " << maxChain[i].profit << ") ";
}

// comparator function for sort function
int compare(Job x, Job y)
{
  return x.start < y.start;
}

// Driver Function
int main()
{
  Job a[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {20, 100, 200}};
  int n = sizeof(a) / sizeof(a[0]);

  vector<Job> arr(a, a + n);
  sort(arr.begin(), arr.end(), compare);

  findMaxProfit(arr);

  return 0;
}
