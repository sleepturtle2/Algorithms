/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

Examples:

Input: Four Jobs with following
deadlines and profits
JobID  Deadline  Profit
  a      4        20
  b      1        10
  c      1        40
  d      1        30
Output: Following is maximum
profit sequence of jobs
        c, a


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum
profit sequence of jobs
        c, a, e
A Simple Solution is to generate all subsets of a given set of jobs and check individual subsets for the feasibility of jobs in that subset. Keep track of maximum profit among all feasible subsets. The time complexity of this solution is exponential.
This is a standard Greedy Algorithm problem. */
#include <iostream>
#include <algorithm>
using namespace std;

// A structure to represent a job
struct Job
{
  char id;    // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
  return (a.profit > b.profit);
}

// Returns minimum number of platforms reqquired
void printJobScheduling(Job arr[], int n)
{
  // Sort all jobs according to decreasing order of prfit
  sort(arr, arr + n, comparison);

  int result[n]; // To store result (Sequence of jobs)
  bool slot[n];  // To keep track of free time slots

  // Initialize all slots to be free
  for (int i = 0; i < n; i++)
    slot[i] = false;

  // Iterate through all given jobs
  for (int i = 0; i < n; i++)
  {
    // Find a free slot for this job (Note that we start
    // from the last possible slot)
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
    {
      // Free slot found
      if (slot[j] == false)
      {
        result[j] = i;  // Add this job to result
        slot[j] = true; // Make this slot occupied
        break;
      }
    }
  }

  // Print the result
  for (int i = 0; i < n; i++)
    if (slot[i])
      cout << arr[result[i]].id << " ";
}

// Driver code
int main()
{
  Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Following is maximum profit sequence of jobs \n";

  // Function call
  printJobScheduling(arr, n);
  return 0;
}
/*
Output
Following is maximum profit sequence of jobs
c a e
The Time Complexity of the above solution is O(n2). It can be optimized using Disjoint Set Data Structure. Please refer to the below post for details.
*/
