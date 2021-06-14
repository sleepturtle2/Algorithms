//https://www.geeksforgeeks.org/maximum-bipartite-matching/
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
