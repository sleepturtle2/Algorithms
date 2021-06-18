//https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
#include <bits/stdc++.h>
using namespace std;

//structure for storing cell data
struct cell
{
  int x, y;
  int dis;
  cell() {}
  cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int N)
{
  if (x >= 1 && x <= N && y >= 1 && y <= N)
    return true;
  return false;
}

int minStepsToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int N)
{

  //directions of movement
  vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
  vector<int> dy = {-1, -2, -2, -1, 1, 2, 2, 1};

  //queue for storing states of knight in board
  queue<cell> queue;

  //push starting position of knight with 0 distance
  queue.push(cell(knightPos[0], knightPos[1], 0));

  cell current;

  int x, y;
  vector<vector<bool>> visited(N + 1, vector<bool>(N + 1));

  //visit starting state
  visited[knightPos[0]][knightPos[1]] = true;

  //bfs
  while (!queue.empty())
  {
    current = queue.front();
    queue.pop();

    //if current cell is target cell, return its distance
    if (current.x == targetPos[0] && current.y == targetPos[1])
      return current.dis;

    //loop for all reachable states
    for (int i = 0; i < 8; i++)
    {
      x = current.x + dx[i];
      y = current.y + dy[i];

      //if reachable state is not visited yet and inside the board, push that state into queue
      if (isInside(x, y, N) && !visited[x][y])
      {
        visited[x][y] = true;
        queue.push(cell(x, y, current.dis + 1));
      }
    }
  }
  return -1;
}

int main()
{
  int N = 30;
  vector<int> knightPos = {1, 1};
  vector<int> targetPos = {30, 30};
  cout << minStepsToReachTarget(knightPos, targetPos, N) << endl;
}
