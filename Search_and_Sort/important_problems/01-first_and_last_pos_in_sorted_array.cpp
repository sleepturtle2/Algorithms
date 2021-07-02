/*
Given a sorted array with possibly duplicate elements. The task is to find indexes of first and last occurrences of an element X in the given array.

Note: If the element is not present in the array return {-1,-1} as pair.
*/

#include <bits/stdc++.h>
using namespace std;
long leftMost(vector<long long> &v, long long x)
{
  long start = 0;
  long end = v.size() - 1;
  long res = -1;
  while (start <= end)
  {
    long mid = start + (end - start) / 2;
    if (v[mid] == x)
    {
      res = mid;
      end = mid - 1;
    }
    else if (x > v[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return res;
}

long rightMost(vector<long long> &v, long long x)
{
  long start = 0;
  long end = v.size() - 1;
  long res = -1;
  while (start <= end)
  {
    long mid = start + (end - start) / 2;
    if (v[mid] == x)
    {
      res = mid;
      start = mid + 1;
    }
    else if (x > v[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return res;
}
pair<long, long> indexes(vector<long long> v, long long x)
{
  // code here
  long left = leftMost(v, x);
  long right = rightMost(v, x);
  pair<long, long> p;
  p.first = left;
  p.second = right;
  return p;
}

pair<long, long> indexes2(vector<long long> &v, int x)
{
  pair<long, long> res = {-1, -1};
  auto leftMost = lower_bound(v.begin(), v.end(), x);
  if (leftMost == v.end() || (*leftMost) != x)
    return res;
  auto rightMost = upper_bound(v.begin(), v.end(), x);
  res.first = leftMost - v.begin();
  res.second = rightMost - v.begin() - 1;
  return res;
}

int main()
{
  vector<long long> v = {1, 3, 5, 5, 5, 5, 67, 123, 125};
  pair<long, long> ans = indexes(v, 5);
  cout << ans.first << " " << ans.second << " " << endl;

  ans = indexes2(v, 5);
  cout << ans.first << " " << ans.second << " " << endl;
}
