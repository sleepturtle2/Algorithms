/*
Note: 
A faster solution would be to simply check if there is a cycle in the graph using the dfs
refer to the problem, how to detect a cycle in a directed graph using dfs. 
if true, then topo sort not possible 
else possible
*/

//https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/
//https : //leetcode.com/problems/course-schedule/

// find whether it is possible to finish all tasks or not from given dependencies

#include <bits/stdc++.h>
using namespace std;

//returns adjacency list from a list of pairs
vector<unordered_set<int>> make_graph(int numTasks, vector<pair<int, int>> &prerequisites)
{
  vector<unordered_set<int>> graph(numTasks);
  for (auto pre : prerequisites)
    graph[pre.second].insert(pre.first);

  return graph;
}

//check if there is a cycle in the directed graph
bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
{
  if (visited[node])
    return false;
  onpath[node] = visited[node] = true;

  for (int neigh : graph[node])
    if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
      return true;
  return onpath[node] = false;
}

bool canFinish(int numTasks, vector<pair<int, int>> &prerequisites)
{

  vector<unordered_set<int>> graph = make_graph(numTasks, prerequisites);
  vector<bool> onpath(numTasks);
  vector<bool> visited(numTasks);

  for (int i = 0; i < numTasks; i++)
    if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
      return false;

  return true;
}

int main()
{
  int numTasks = 4;
  vector<pair<int, int>> prerequisites;
  prerequisites.push_back(make_pair(1, 0));
  prerequisites.push_back(make_pair(2, 1));
  prerequisites.push_back(make_pair(3, 2));

  if (canFinish(numTasks, prerequisites))
    cout << "Possible to finish all tasks\n";
  else
    cout << "Impossible to finish all tasks\n";
}
