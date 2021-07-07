//classic job scheduling / activity selection problem

//if we sort by finish times, it is a greedy problem
//if we sort by start times, it is a DP problem. we need to find the LIS

/*
L[i] = jobs[i] + { max(L[j]), where j < i and jobs[j].end < jobs[i].start }
     = jobs[i], if there is no such j
 */

/*
{0, 6} {1, 4} {2, 13} {3, 5} {3, 8} {5, 7} {5, 9} {6, 10} {8, 11} {8, 12} {12, 14}

L[] would be:
L[0]: {0, 6}
L[1]: {1, 4}
L[2]: {2, 13}
L[3]: {3, 5}
L[4]: {3, 8}
L[5]: {1, 4} {5, 7}
L[6]: {1, 4} {5, 9}
L[7]: {1, 4} {6, 10}
L[8]: {1, 4} {5, 7} {8, 11}
L[9]: {1, 4} {5, 7} {8, 12}
L[10]: {1, 4} {5, 7} {8, 11} {12, 14}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

// Data structure to store the start and finish time of the jobs.
struct Pair
{
  int start;
  int finish;
};

// print  the maximum number of non-conflicting jobs that can be performed
// by a single person
void printNonConflictingJobs(vector<Pair> jobs) // no-ref, no-const
{
  // sort the jobs according to increasing order of their start time
  sort(jobs.begin(), jobs.end(),
       [](Pair &x, Pair &y)
       {
         return x.start < y.start;
       });

  // `L[i]` stores the maximum non-conflicting jobs that end at i'th job
  vector<vector<Pair>> L(jobs.size());

  for (int i = 0; i < jobs.size(); i++)
  {
    // consider each `j` less than `i`
    for (int j = 0; j < i; j++)
    {
      // `L[i] = max(L[j])`, where `jobs[j].finish` is less than `jobs[i].start`
      if (jobs[j].finish < jobs[i].start &&
          L[i].size() < L[j].size())
      {
        L[i] = L[j];
      }
    }

    // `L[i]` ends at i'th job
    L[i].push_back(jobs[i]);
  }

  // find the vector having the maximum size
  vector<Pair> max;
  for (auto &pair : L)
  {
    if (max.size() < pair.size())
    {
      max = pair;
    }
  }

  // print maximum non-conflicting jobs
  for (Pair &pair : max)
  {
    cout << "{" << pair.start << ", " << pair.finish << "} ";
  }
}

//  maximum count of non-conflicting jobs that can be performed
// by a single person
int countNonConflictingJobsLength(vector<Pair> jobs) // no-ref, no-const
{
  // sort the jobs according to increasing order of their start time
  sort(jobs.begin(), jobs.end(),
       [](Pair &x, Pair &y)
       {
         return x.start < y.start;
       });

  // `L[i]` stores the maximum count of non-conflicting jobs ending at i'th job
  vector<int> L(jobs.size());
  int max_element = INT_MIN;
  for (int i = 0; i < jobs.size(); i++)
  {
    // consider each `j` less than `i`
    for (int j = 0; j < i; j++)
    {
      // `L[i] = max(L[j])`, where `jobs[j].finish` is less than `jobs[i].start`
      if (jobs[j].finish < jobs[i].start && L[i] < L[j])
      {
        L[i] = L[j];
      }
    }

    // increment `L[i]` since it ends at the i'th job
    L[i]++;
    max_element = max(max_element, L[i]);
  }

  // return the maximum job length in the vector
  return max_element;
}

int main()
{
  // Each pair stores the start and the finish time of a job
  vector<Pair> jobs =
      {
          {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};

  cout << "The maximum count of non-conflicting jobs is "
       << countNonConflictingJobsLength(jobs) << endl;

  printNonConflictingJobs(jobs);
  cout << endl;
  return 0;
}
/*
The maximum count of non-conflicting jobs is 4
{1, 4} {5, 7} {8, 11} {12, 14}
*/
