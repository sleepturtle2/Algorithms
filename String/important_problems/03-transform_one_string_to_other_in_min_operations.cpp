#include <bits/stdc++.h>
using namespace std;

int minTransform(string &s1, string &s2)
{
  if (s1.size() != s2.size())
    return false;

  int n = s1.size();

  unordered_map<char, int> m1;
  unordered_map<char, int> m2;

  for (auto s : s1)
    m1[s]++;
  for (auto s : s2)
    m2[s]++;

  if (m1 == m2)
  {
    int count = 0;

    for (int i = n - 1, j = n - 1; i >= 0;) //very tricky. try to understand why this works
    {
      while (i >= 0 && s1[i] != s2[j])
      {
        i--;
        count++;
      }
      if (i >= 0)
      {
        i--;
        j--;
      }
    }
    return count;
  }
  return -1;
}

int main()
{
  string s1 = "EACBD";
  string s2 = "EABCD";
  cout << minTransform(s1, s2) << endl;
}
