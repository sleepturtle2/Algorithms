//https://www.geeksforgeeks.org/maximum-bipartite-matching/
/*
Let us first define input and output forms. Input is in the form of Edmonds matrix which is a 2D array ‘bpGraph[M][N]’ with M rows (for M job applicants) and N columns (for N jobs). The value bpGraph[i][j] is 1 if i’th applicant is interested in j’th job, otherwise 0. 
Output is number maximum number of people that can get jobs. 
A simple way to implement this is to create a matrix that represents adjacency matrix representation of a directed graph with M+N+2 vertices. Call the fordFulkerson() for the matrix. This implementation requires O((M+N)*(M+N)) extra space. 
Extra space can be reduced and code can be simplified using the fact that the graph is bipartite and capacity of every edge is either 0 or 1. The idea is to use DFS traversal to find a job for an applicant (similar to augmenting path in Ford-Fulkerson). We call bpm() for every applicant, bpm() is the DFS based function that tries all possibilities to assign a job to the applicant.
In bpm(), we one by one try all jobs that an applicant ‘u’ is interested in until we find a job, or all jobs are tried without luck. For every job we try, we do following. 
If a job is not assigned to anybody, we simply assign it to the applicant and return true. If a job is assigned to somebody else say x, then we recursively check whether x can be assigned some other job. To make sure that x doesn’t get the same job again, we mark the job ‘v’ as seen before we make recursive call for x. If x can get other job, we change the applicant for job ‘v’ and return true. We use an array maxR[0..N-1] that stores the applicants assigned to different jobs.
If bmp() returns true, then it means that there is an augmenting path in flow network and 1 unit of flow is added to the result in maxBPM(). 
*/

#include <bits/stdc++.h>
using namespace std;

#define M 6 //M applicants
#define N 6 //N jobs

//a dfs based recursive function that returns true if a matching for vertex u is possible
bool bpm(vector<vector<bool>> &bpGraph, int u, vector<bool> &seen, vector<int> &matchR)
{

  //try every job one by one
  for (int v = 0; v < N; v++)
  {
    //if applicant u is interested in job v and v is not visited
    if (bpGraph[u][v] && !seen[v])
    {

      //mark v as visited
      seen[v] = true;

      // If job 'v' is not assigned to an
      // applicant OR previously assigned
      // applicant for job v (which is matchR[v])
      // has an alternate job available.
      // Since v is marked as visited in
      // the above line, matchR[v] in the following
      // recursive call will not get job 'v' again
      if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
      {
        matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}
//returns the maximum number of matching from M to N
int maxBPM(vector<vector<bool>> &bpGraph)
{
  // An array to keep track of the
  // applicants assigned to jobs.
  // The value of matchR[i] is the
  // applicant number assigned to job i,
  // the value -1 indicates nobody is
  // assigned.
  vector<int> matchR(N, -1);

  //count of jobs assigned to applicants
  int result = 0;
  for (int u = 0; u < M; u++)
  {
    //mark all jobs as not seen for next applicant
    vector<bool> seen(N, false);

    //find if applicant u can get a job
    if (bpm(bpGraph, u, seen, matchR))
      result++;
  }
  return result;
}

int main()
{
  vector<vector<bool>> bpGraph = {{0, 1, 1, 0, 0, 0},
                                  {1, 0, 0, 1, 0, 0},
                                  {0, 0, 1, 0, 0, 0},
                                  {0, 0, 1, 1, 0, 0},
                                  {0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 1}};
  cout << "Maximum number of applicants that can get job is: " << maxBPM(bpGraph) << endl;

  return 0;
}
