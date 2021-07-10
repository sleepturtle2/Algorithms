/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/

#include <bits/stdc++.h>
using namespace std;

string minRemove(string s)
{
  string s1;
  int open = 0;

  //remove unbalanced )
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      open++;
    else if (s[i] == ')')
    {
      if (open == 0) //no preceding '('
        continue;    //dont include the ')'
      open--;
    }
    s1 += s[i];
  }

  string s2; //holds answer
  //here it is guaranteed that there is no unbalanced )
  //so the value of open = no of unbalanced (
  //remove 'open' no of (
  for (int i = s1.size() - 1; i >= 0; i--)
  {
    if (s1[i] == '(' and open-- > 0) //means there are more unbalanced (, so skip adding it
      continue;
    s2 = s1[i] + s2;
  }
  return s2;
}

int main()
{
  string s1 = "lee(t(c)o)de)";
  string s2 = "a)b(c)d";
  string s3 = "))((";
  string s4 = "(a(b(c)d)";

  cout << minRemove(s1) << endl;
  cout << minRemove(s2) << endl;
  cout << minRemove(s3) << endl;
  cout << minRemove(s4) << endl;
}
/*
lee(t(c)o)de
ab(c)d

(a(bc)d)
*/
