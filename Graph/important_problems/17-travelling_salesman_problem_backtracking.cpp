#include <bits/stdc++.h>
using namespace std;

void tsp(vector<vector<int>> &graph, vector<bool> &visited, int currPos, int V, int count, int cost, int &ans)
{

  // If last node is reached and it has a link
  // to the starting node i.e the source then
  // keep the minimum value out of the total cost
  // of traversal and "ans"
  // Finally return to check for more possible values
  if (count == V && graph[currPos][0])
  {
    ans = min(ans, cost + graph[currPos][0]);
    return;
  }

  // BACKTRACKING STEP
  // Loop to traverse the adjacency list
  // of currPos node and increasing the count
  // by 1 and cost by graph[currPos][i] value
  for (int i = 0; i < V; i++)
  {
    if (!visited[i] && graph[currPos][i])
    {

      visited[i] = true;
      tsp(graph, visited, i, V, count + 1, cost + graph[currPos][i], ans);

      //mark ith node as unvisited
      visited[i] = false;
    }
  }
}

int main()
{
  vector<vector<int>> graph = {
      {0, 10, 15, 20},
      {10, 0, 35, 25},
      {15, 35, 0, 30},
      {20, 25, 30, 0}};

  int V = graph.size();
  vector<bool> visited(V);

  visited[0] = true;
  int ans = INT_MAX;

  //find minimum weight Hamiltonian cycle
  tsp(graph, visited, 0, V, 1, 0, ans);
  cout << ans << endl;
}
