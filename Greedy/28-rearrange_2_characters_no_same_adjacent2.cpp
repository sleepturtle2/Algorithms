/*
Another approach :
Another approach is to fill all the even positions of the result string first, with the highest frequency character. If there are still some even positions remaining, fill them first. Once even positions are done, then fill the odd positions. This way, we can ensure that no two adjacent characters are the same.
*/

#include <bits/stdc++.h>
using namespace std;

char getMaxCountChar(const vector<int> &count)
{
  int max = 0;
  char ch;
  for (int i = 0; i < 26; i++)
  {
    if (count[i] > max)
    {
      max = count[i];
      ch = 'a' + i;
    }
  }

  return ch;
}

string rearrangeString(string S)
{

  int n = S.size();
  if (!n)
    return "";

  vector<int> count(26, 0);
  for (auto ch : S)
    count[ch - 'a']++;

  char ch_max = getMaxCountChar(count);
  int maxCount = count[ch_max - 'a'];

  // check if the result is possible or not
  if (maxCount > (n + 1) / 2)
    return "";

  string res(n, ' ');

  int ind = 0;
  // filling the most frequently occuring char in the even
  // indices
  while (maxCount)
  {
    res[ind] = ch_max;
    ind = ind + 2;
    maxCount--;
  }
  count[ch_max - 'a'] = 0;

  // now filling the other Chars, first filling the even
  // positions and then the odd positions
  for (int i = 0; i < 26; i++)
  {
    while (count[i] > 0)
    {
      ind = (ind >= n) ? 1 : ind;
      res[ind] = 'a' + i;
      ind += 2;
      count[i]--;
    }
  }
  return res;
}

// Driver program to test above function
int main()
{
  string str = "bbbaa";
  string res = rearrangeString(str);
  if (res == "")
    cout << "Not valid string" << endl;
  else
    cout << res << endl;
  return 0;
}
/*
Output

babab
Time complexity : O(n)

Space complexity : O(n+26) where 26 is the size of the vocabulary. */
