//https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
/*

Build as many bridges across a river as possible.
Points across the river will be provided in pairs
Pair = (point on north bank, point on south bank)
Only points in these pairs can be joined to form bridges
No bridges should be crossing each other

*/

#include <bits/stdc++.h>
using namespace std;

struct CityPairs
{
  int north, south;
};

bool compare(struct CityPairs a, struct CityPairs b)
{
  if (a.south == b.south)
    return a.north < b.north;
  return a.south < b.south;
}

int maxBridges(struct CityPairs values[], int n)
{
  int lis[n];
  for (int i = 0; i < n; i++)
    lis[i] = 1;

  sort(values, values + n, compare);
  int res = INT_MIN;
  //lis of northern coordinates
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (values[i].north > values[j].north && lis[i] < 1 + lis[j])
      {
        lis[i] = 1 + lis[j];
        res = max(res, lis[i]);
      }

  return res;
}

int main()
{
  struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
  int n = 4;
  cout << "Maximum number of bridges = " << maxBridges(values, n) << endl; // 2 (answer)
}
//o(n2)
