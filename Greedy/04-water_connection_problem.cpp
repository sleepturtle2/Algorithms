/*
Every house in the colony has at most one pipe going into it and at most one pipe going out of it. Tanks and taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roof and every house with only an incoming pipe and no outgoing pipe gets a tap.’
Given two integers n and p denoting the number of houses and the number of pipes. The connections of pipe among the houses contain three input values: a_i, b_i, d_i denoting the pipe of diameter d_i from house a_i to house b_i, find out the efficient solution for the network.
The output will contain the number of pairs of tanks and taps t installed in first line and the next t lines contain three integers: house number of tank, house number of tap and the minimum diameter of pipe between them.*/
/*
Input : 4 2
        1 2 60
        3 4 50
Output :2
        1 2 60
        3 4 50
Explanation:
Connected components are:
1->2 and 3->4
Therefore, our answer is 2 followed by
1 2 60 and 3 4 50.

Input :9 6
       7 4 98
       5 9 72
       4 6 10
       2 8 22
       9 7 17
       3 1 66
Output :3
        2 8 22
        3 1 66
        5 6 10
Explanation:
Connected components are 3->1,
5->9->7->4->6 and 2->8.
Therefore, our answer is 3 followed by
2 8 22, 3 1 66, 5 6 10*/

/*
Approach:
Perform DFS from appropriate houses to find all different connected components. The number of different connected components is our answer t.
The next t lines of the output are the beginning of the connected component, end of the connected component and the minimum diameter from the start to the end of the connected component in each line.
Since, tanks can be installed only on the houses having outgoing pipe and no incoming pipe, therefore these are appropriate houses to start DFS from i.e. perform DFS from such unvisited houses.

*/

#include <bits/stdc++.h>
using namespace std;

// number of houses and number
// of pipes
int n, p;

// Array rd stores the
// ending vertex of pipe
int rd[1100];

// Array wd stores the value
// of diameters between two pipes
int wt[1100];

// Array cd stores the
// starting end of pipe
int cd[1100];

// Vector a, b, c are used
// to store the final output
vector<int> a;
vector<int> b;
vector<int> c;

int ans;

int dfs(int w)
{
  if (cd[w] == 0)
    return w;
  if (wt[w] < ans)
    ans = wt[w];
  return dfs(cd[w]);
}

// Function performing calculations.
void solve(int arr[][3])
{
  int i = 0;

  while (i < p)
  {

    int q = arr[i][0], h = arr[i][1],
        t = arr[i][2];

    cd[q] = h;
    wt[q] = t;
    rd[h] = q;
    i++;
  }

  a.clear();
  b.clear();
  c.clear();

  for (int j = 1; j <= n; ++j)

    /*If a pipe has no ending vertex
        but has starting vertex i.e is
        an outgoing pipe then we need
        to start DFS with this vertex.*/
    if (rd[j] == 0 && cd[j])
    {
      ans = 1000000000;
      int w = dfs(j);

      // We put the details of component
      // in final output array
      a.push_back(j);
      b.push_back(w);
      c.push_back(ans);
    }

  cout << a.size() << endl;
  for (int j = 0; j < a.size(); ++j)
    cout << a[j] << " " << b[j]
         << " " << c[j] << endl;
}

// driver function
int main()
{
  n = 9, p = 6;

  memset(rd, 0, sizeof(rd));
  memset(cd, 0, sizeof(cd));
  memset(wt, 0, sizeof(wt));

  int arr[][3] = {{7, 4, 98},
                  {5, 9, 72},
                  {4, 6, 10},
                  {2, 8, 22},
                  {9, 7, 17},
                  {3, 1, 66}};

  solve(arr);
  return 0;
}
/*
Output:

3
2 8 22
3 1 66
5 6 10
*/
