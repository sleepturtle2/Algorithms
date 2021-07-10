/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include <bits/stdc++.h>
using namespace std;

int sliding_window(string s)
{
  vector<int> chars(128); //being used as a hash table

  int left = 0;
  int right = 0;

  int res = 0;
  while (right < s.length())
  {
    char r = s[right];
    chars[r]++;

    while (chars[r] > 1)
    {
      char l = s[left];
      chars[l]--;
      left++;
    }

    res = max(res, right - left + 1);
    right++;
  }
  return res;
}

int sliding_window_optimized(string s)
{
  vector<int> chars(128, -1);

  int left = 0;
  int right = 0;

  int res = 0;

  while (right < s.length())
  {
    char r = s[right];
    int index = chars[r];
    if (index != -1 and index >= left and index < right)
    {
      left = index + 1;
    }
    res = max(res, right - left + 1);

    chars[r] = right;
    right++;
  }
  return res;
}

int main()
{
  string s = "abcabcbb";
  cout << sliding_window(s) << endl;
  /*O(2n), 2 traversals
  Space complexity : O(min(m, n))O(min(m,n)). Same as the previous approach. We need O(k)O(k) space for the sliding window, where kk is the size of the Set. The size of the Set is upper bounded by the size of the string nn and the size of the charset/alphabet mm.*/

  cout << sliding_window_optimized(s) << endl; //o(n), 1 traversal
  /*
  Complexity Analysis

Time complexity : O(n)O(n). Index jj will iterate nn times.

Space complexity (HashMap) : O(min(m, n))O(min(m,n)). Same as the previous approach.

Space complexity (Table): O(m)O(m). mm is the size of the charset.*/
}
