//https://www.geeksforgeeks.org/find-the-number-of-islands-set-2-using-disjoint-set/

#include <bits/stdc++.h>
using namespace std;

//class to represent the Disjoint Set Data Structure
class DisjointUnionSets
{

  vector<int> rank, parent;
  int n;

public:
  DisjointUnionSets(int n)
  {
    rank.resize(n);
    parent.resize(n);
    this->n = n;
    makeSet();
  }

  void makeSet()
  {
    //initially all elements are in their own set
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  //find representative of the set that x is an element of
  int find(int x)
  {
    if (parent[x] != x)
    {
      //if x is not the parent of itself, then x is not a representative of its set
      //we recursively call find on its parent and move i's node directly under the representative of the set
      return find(parent[x]);
    }

    return x;
  }

  //unites the set that includes x and the set that includes y
  void Union(int x, int y)
  {
    //find the representatives (or the root node) for x and y
    int xRoot = find(x);
    int yRoot = find(y);

    //elements in the same set, no need to unite anything
    if (xRoot == yRoot)
      return;

    //if x's rank is less than y's rank then move x under y so that the depth of tree remains less
    if (rank[xRoot] < rank[yRoot])
      parent[yRoot] = xRoot;
    else
    { //if ranks are same

      parent[yRoot] = xRoot;
      rank[xRoot] = rank[xRoot] + 1;
    }
  }
};

int countIslands(vector<vector<int>> &a)
{
  int n = a.size();
  int m = a[0].size();

  DisjointUnionSets *dus = new DisjointUnionSets(n * m);

  //checks for neighbors and unites the indices if both are 1
  for (int j = 0; j < n; j++)
  {
    for (int k = 0; k < m; k++)
    {

      //if cell has 0, nothing to do
      if (a[j][k] == 0)
        continue;

      //check all 8 neighbors and do a union with neighbors set if neighbor is also 1

      if (j + 1 < n && a[j + 1][k] == 1)
        dus->Union(j * (m) + k,
                   (j + 1) * (m) + k);
      if (j - 1 >= 0 && a[j - 1][k] == 1)
        dus->Union(j * (m) + k,
                   (j - 1) * (m) + k);
      if (k + 1 < m && a[j][k + 1] == 1)
        dus->Union(j * (m) + k,
                   (j) * (m) + k + 1);
      if (k - 1 >= 0 && a[j][k - 1] == 1)
        dus->Union(j * (m) + k,
                   (j) * (m) + k - 1);
      if (j + 1 < n && k + 1 < m &&
          a[j + 1][k + 1] == 1)
        dus->Union(j * (m) + k,
                   (j + 1) * (m) + k + 1);
      if (j + 1 < n && k - 1 >= 0 &&
          a[j + 1][k - 1] == 1)
        dus->Union(j * m + k,
                   (j + 1) * (m) + k - 1);
      if (j - 1 >= 0 && k + 1 < m &&
          a[j - 1][k + 1] == 1)
        dus->Union(j * m + k,
                   (j - 1) * m + k + 1);
      if (j - 1 >= 0 && k - 1 >= 0 &&
          a[j - 1][k - 1] == 1)
        dus->Union(j * m + k,
                   (j - 1) * m + k - 1);
    }
  }

  //array to note down frequency of each set
  vector<int> c(n * m);
  int numberOfIslands = 0;

  for (int j = 0; j < n; j++)
  {
    for (int k = 0; k < m; k++)
    {
      if (a[j][k] == 1)
      {
        int x = dus->find(j * m + k);

        //if frequency is set to 0, increment islands
        if (c[x] == 0)
        {
          numberOfIslands++;
          c[x]++;
        }
        else
          c[x]++;
      }
    }
  }
  return numberOfIslands;
}

int main()
{
  vector<vector<int>> a = {{1, 1, 0, 0, 0},
                           {0, 1, 0, 0, 1},
                           {1, 0, 0, 1, 1},
                           {0, 0, 0, 0, 0},
                           {1, 0, 1, 0, 1}};
  cout << "Number of islands is: " << countIslands(a) << endl;
  return 0;
}
