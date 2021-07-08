/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.


A Simple Solution is to generate all subsets of a given set of jobs and check individual subsets for the feasibility of jobs in that subset. Keep track of maximum profit among all feasible subsets. The time complexity of this solution is exponential.
This is a standard Greedy Algorithm problem.
Following is the algorithm.

1) Sort all jobs in decreasing order of profit.
2) Iterate on jobs in decreasing order of profit.For each job , do the following :



For each job find an empty time slot from deadline to 0. If found empty slot put the job in the slot and mark this slot filled. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Stores the maximum deadline that can be associated with a job
#define T 15

// Data structure to store job details. Each job has an identifier,
// a deadline, and profit associated with it.
struct Job
{
  int taskID, deadline, profit;
};

// Function to schedule jobs to maximize profit
void scheduleJobs(vector<Job> jobs) // no-ref, no-const
{
  // stores the maximum profit that can be earned by scheduling jobs
  int profit = 0;

  // array to store used and unused slots info
  vector<int> slot(T, -1);

  // arrange the jobs in decreasing order of their profits
  sort(jobs.begin(), jobs.end(),
       [](Job &a, Job &b)
       {
         return a.profit > b.profit; // using C++11 lambda comparison
       });

  // consider each job in decreasing order of their profits
  for (const Job &job : jobs)
  {
    // search for the next free slot and map the task to that slot
    for (int j = job.deadline - 1; j >= 0; j--)
    {
      if (j < T && slot[j] == -1)
      {
        slot[j] = job.taskID;
        profit += job.profit;
        break;
      }
    }
  }

  // print the scheduled jobs
  cout << "The scheduled jobs are ";
  for (int i = 0; i < T; i++)
  {
    if (slot[i] != -1)
    {
      cout << slot[i] << " ";
    }
  }

  // print the total profit that can be earned
  cout << "\nThe total profit earned is " << profit;
}

int main()
{
  // vector of given jobs. Each job has an identifier, a deadline, and
  // profit associated with it
  vector<Job> jobs =
      {
          {1, 9, 15}, {2, 2, 2}, {3, 5, 18}, {4, 7, 1}, {5, 4, 25}, {6, 2, 20}, {7, 5, 8}, {8, 7, 10}, {9, 4, 12}, {10, 3, 5}};

  // schedule jobs and calculate the maximum profit
  scheduleJobs(jobs);

  return 0;
}
/*
Output
The scheduled jobs are 7 6 9 5 3 4 8 1
The total profit earned is 109
The Time Complexity of the above solution is O(n2). It can be optimized using Disjoint Set Data Structure.
*/
