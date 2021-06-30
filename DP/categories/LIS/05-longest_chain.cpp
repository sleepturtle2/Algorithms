//https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Find the longest chain which can be formed from a given set of pairs.
For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
*/

#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
  int a;
  int b;
};

int maxChainLength(Pair arr[], int n)
{
  int res = 0;
  vector<int> mcl(n, 1); //initialise with 1

  //apply lis logic here
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1)
      {
        mcl[i] = mcl[j] + 1;
        res = max(res, mcl[i]);
      }
  return res;
}
bool compare(struct Pair a, struct Pair b)
{

  if (a.a == b.a)
    return a.b < b.a;

  return a.a < b.a;
}

int main()
{
  Pair arr[] = {{27, 40}, {5, 24}, {15, 25}, {50, 60}, {39, 60}};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n, compare); // is this an essential step? (i think so)
  cout << maxChainLength(arr, n) << endl;
}
//o(n2)
