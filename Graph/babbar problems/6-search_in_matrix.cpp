//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

bool isSafe(int row, int col, vector<vector<int>> &matrix, int n, vector<vector<bool>> &visited)
{
  if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || matrix[row][col] == 0)
    return false;

  return true;
}

//possible paths from (0,0) to (n-1, n-1)
void printPathUtil(int row, int col, vector<vector<int>> &matrix, int n, string &path, vector<string> &possiblePaths, vector<vector<bool>> &visited)
{

  //check initial point to start the path
  if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || matrix[row][col] == 0)
    return;

  //if last cell(n-1, n-1) is reached, store the path and return
  if (row == n - 1 && col == n - 1)
  {
    possiblePaths.push_back(path);
    return;
  }

  //mark starting cell as visited
  visited[row][col] = true;

  //try all 4 directions (down, left, right, up) in order to get path in lexicographical order

  //check if downward move is valid
  if (isSafe(row + 1, col, matrix, n, visited))
  {
    path.push_back('D');
    printPathUtil(row + 1, col, matrix, n, path, possiblePaths, visited);
    path.pop_back();
  }

  //check if left move is valid
  if (isSafe(row, col - 1, matrix, n, visited))
  {
    path.push_back('L');
    printPathUtil(row, col - 1, matrix, n, path, possiblePaths, visited);
    path.pop_back();
  }

  //check if right move is valid
  if (isSafe(row, col + 1, matrix, n, visited))
  {
    path.push_back('R');
    printPathUtil(row, col + 1, matrix, n, path, possiblePaths, visited);
    path.pop_back();
  }

  //check if the up move is valid
  if (isSafe(row - 1, col, matrix, n, visited))
  {
    path.push_back('U');
    printPathUtil(row - 1, col, matrix, n, path, possiblePaths, visited);
    path.pop_back();
  }

  //mark the cell as unvisited for other possible paths
  visited[row][col] = false;
}

void printPath(vector<vector<int>> &matrix, int n)
{

  //to store all possible paths
  vector<string> possiblePaths;
  string path;
  vector<vector<bool>> visited(n, vector<bool>(SIZE));

  //utility to find all valid paths
  printPathUtil(0, 0, matrix, n, path, possiblePaths, visited);

  //print all possible paths
  for (int i = 0; i < possiblePaths.size(); i++)
    cout << possiblePaths[i] << " ";
  cout << endl;
}
int main()
{
  vector<vector<int>> matrix(SIZE, vector<int>(SIZE));
  matrix = {{1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1}};
  int n = matrix.size();
  printPath(matrix, n);
}
