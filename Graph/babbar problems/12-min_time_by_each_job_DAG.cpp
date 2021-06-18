//https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
#include <bits/stdc++.h>
#include "../graph headers/unweighted_DAG.h"
using namespace std;

void minTimeForJobs(vector<vector<int>> &adj, int V)
{
  vector<int> indegree(V);
  int E = 0;
  vector<int> min_time(V);

  //count edges and indegree of nodes
  for (int i = 0; i < V; i++)
    for (int v : adj[i])
    {
      E++;
      indegree[v]++;
    }

  //find topo sort using indegree approach

  queue<int> queue;

  //enqueue nodes with 0 indegree
  for (int i = 0; i < V; i++)
    if (indegree[i] == 0)
    {
      queue.push(i);
      min_time[i] = 1;
    }

  while (!queue.empty())
  {
    int current = queue.front();
    queue.pop();

    for (int v : adj[current])
    {
      indegree[v]--;

      if (indegree[v] == 0)
        min_time[v] = min_time[current] + 1;

      queue.push(v);
    }
  }

  //print min time for every job
  for (int i = 0; i < V; i++)
    cout << min_time[i] << " ";
  cout << endl;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj2;
  int V = adj.size();

  minTimeForJobs(adj, V);
}
