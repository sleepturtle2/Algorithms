//https://www.geeksforgeeks.org/flood-fill-algorithm/
#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
  if (x < 0 || y < 0)
    return false;

  if (x >= n || y >= m)
    return false;

  return true;
}

void floodFill(vector<vector<int>> &screen, int x, int y, int newColor)
{
  int n = screen.size();
  int m = screen[0].size();

  vector<vector<bool>> visited(screen.size(), vector<bool>(screen[0].size()));
  queue<pair<int, int>> queue; //stores the coordinates
  queue.push({x, y});

  visited[x][y] = true;

  while (!queue.empty())
  {
    //front pair
    pair<int, int> coord = queue.front();
    queue.pop();
    x = coord.first;
    y = coord.second;
    int prevColor = screen[x][y];

    screen[x][y] = newColor;

    //upside pixel
    if (isValid(x + 1, y, n, m) && !visited[x + 1][y] && screen[x + 1][y] == prevColor)
    {
      queue.push({x + 1, y});
      visited[x + 1][y] = true;
    }

    //downwards pixel
    if (isValid(x - 1, y, n, m) && !visited[x - 1][y] && screen[x - 1][y] == prevColor)
    {
      queue.push({x - 1, y});
      visited[x - 1][y] = true;
    }

    //right pixel
    if (isValid(x, y + 1, n, m) && !visited[x][y + 1] && screen[x][y + 1] == prevColor)
    {
      queue.push({x, y + 1});
      visited[x][y + 1] = true;
    }

    //left side of pixel
    if (isValid(x, y - 1, n, m) && !visited[x][y - 1] && screen[x][y - 1] == prevColor)
    {
      queue.push({x, y - 1});
      visited[x][y - 1] = true;
    }
  }

  //printing the changed matrix of pixels
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << screen[i][j] << " ";

    cout << "\n";
  }
}

int main()
{
  vector<vector<int>> screen = {
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 1, 0, 1, 1},
      {1, 2, 2, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 2, 2, 0},
      {1, 1, 1, 1, 1, 2, 1, 1},
      {1, 1, 1, 1, 1, 2, 2, 1},
  };

  int x = 4, y = 4, newColor = 3;
  floodFill(screen, x, y, newColor);

  cout << "Updated screen:\n";
  for (int i = 0; i < screen.size(); i++)
  {
    for (int j = 0; j < screen[0].size(); j++)
      cout << screen[i][j] << " ";
    cout << "\n";
  }
}
