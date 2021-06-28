#include <bits/stdc++.h>
using namespace std;

bool isScrambled(string a, string b, unordered_map<string, bool> &map)
{
  if (a.compare(b) == 0)
    return true;

  if (a.length() != b.length())
    return false;
  if (a.length() <= 1)
    return false;

  string key = a;
  key.push_back(' ');
  key.append(b);

  if (map.find(key) != map.end())
    return map[key];

  int n = a.length();
  bool flag = false;

  for (int i = 1; i < n; i++)
  { //compare first and last parts respectively
    bool condition1 = isScrambled(a.substr(0, i), b.substr(n - i, i), map) and isScrambled(a.substr(i, n - i), b.substr(0, n - i), map);
    //compare first with first and last with last
    bool condition2 = isScrambled(a.substr(0, i), b.substr(0, i), map) and isScrambled(a.substr(i, n - i), b.substr(i, n - i), map);

    if (condition1 || condition2)
    {
      flag = true;
      break;
    }
  }
  return map[key] = flag;
}

int main()
{
  string s1 = "coder";
  string s2 = "ocred";

  unordered_map<string, bool> map;
  if (isScrambled(s1, s2, map))
    cout << "Yes\n";
  else
    cout << "No\n";
}
