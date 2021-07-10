/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/
/*
Intuition
To make the string valid with minimum removals, we need to get rid of all parentheses that do not have a matching pair.

Push char index into the stack when we see '('.

Pop from the stack when we see ')'.

If the stack is empty, then we have ')' without the pair, and it needs to be removed.
In the end, the stack will contain indexes of '(' without the pair, if any. We need to remove all of them too.

Approach : Stack and Placeholder
We mark removed parentheses with '*', and erase all of them in the end.
*/

#include <bits/stdc++.h>
using namespace std;

string minRemove(string s)
{
  stack<int> st; //tracks the indices of unbalanced '('
  for (auto i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      st.push(i);
    if (s[i] == ')')
    {
      if (!st.empty())
        st.pop(); //means this '(' is balanced
      else
        s[i] = '*'; //mark for removal later
    }
  }
  while (!st.empty())
  {
    s[st.top()] = '*';
    st.pop();
  }
  s.erase(remove(s.begin(), s.end(), '*'), s.end()); //removed the unbalanced ) marked by *
  return s;
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
