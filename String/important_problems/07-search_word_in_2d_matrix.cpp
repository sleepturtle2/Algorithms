/*
Given a 2D grid of characters and a word, find all occurrences of the given word in the grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonal directions.
*/
#include <bits/stdc++.h>
using namespace std;

// For searching in all 8 direction
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char *grid, int row, int col,
              string word, int R, int C)
{
  // If first character of word doesn't
  // match with given starting point in grid.
  if (*(grid + row * C + col) != word[0])
    return false;

  int len = word.length();

  // Search word in all 8 directions
  // starting from (row, col)
  for (int dir = 0; dir < 8; dir++)
  {
    // Initialize starting point
    // for current direction
    int k, rd = row + x[dir], cd = col + y[dir];

    // First character is already checked,
    // match remaining characters
    for (k = 1; k < len; k++)
    {
      // If out of bound break
      if (rd >= R || rd < 0 || cd >= C || cd < 0)
        break;

      // If not matched,  break
      if (*(grid + rd * C + cd) != word[k])
        break;

      // Moving in particular direction
      rd += x[dir], cd += y[dir];
    }

    // If all character matched, then value of k must
    // be equal to length of word
    if (k == len)
      return true;
  }
  return false;
}

// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char *grid, string word,
                   int R, int C)
{
  // Consider every point as starting
  // point and search given word
  for (int row = 0; row < R; row++)
    for (int col = 0; col < C; col++)
      if (search2D(grid, row, col, word, R, C))
        cout << "pattern found at "
             << row << ", "
             << col << endl;
}

// Driver program
int main()
{
  int R = 3, C = 13;
  char grid[R][C] = {"GEEKSFORGEEKS",
                     "GEEKSQUIZGEEK",
                     "IDEQAPRACTICE"};

  patternSearch((char *)grid, "GEEKS", R, C);
  cout << endl;
  patternSearch((char *)grid, "EEE", R, C);
  return 0;
}
/*
Time complexity: O(R*C).
All the cells will be visited and traversed in all 8 directions, where R and C is side of matrix so time complexity is O(R*C).
Auxiliary Space: O(1).
As no extra space is needed.
*/
