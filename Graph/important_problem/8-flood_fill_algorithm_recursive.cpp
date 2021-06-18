//https://www.geeksforgeeks.org/flood-fill-algorithm/
#include <bits/stdc++.h>
using namespace std;

//replace prevColor with newColor and all surrounding cells
void floodFillUtil(vector<vector<int>> &screen, int x, int y, int prevColor, int newColor)
{
  //base cases
  if (x < 0 || x >= screen.size() || y < 0 || y >= screen[0].size())
    return;
  if (screen[x][y] != prevColor)
    return;
  if (screen[x][y] == newColor)
    return;

  //replace color at (x,y)
  screen[x][y] = newColor;

  //recur for all directions
  floodFillUtil(screen, x + 1, y, prevColor, newColor);
  floodFillUtil(screen, x - 1, y, prevColor, newColor);
  floodFillUtil(screen, x, y + 1, prevColor, newColor);
  floodFillUtil(screen, x, y - 1, prevColor, newColor);
}

void floodFill(vector<vector<int>> &screen, int x, int y, int newColor)
{
  int prevColor = screen[x][y];
  if (prevColor != newColor)
    floodFillUtil(screen, x, y, prevColor, newColor);
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
