#include <bits/stdc++.h>
using namespace std;

#define d 256 //number of characters in the input alphabet. for standard problems, take d as 26

//q is a prime number
void search(char pat[], char txt[], int q)
{
  int pat_len = strlen(pat);
  int txt_len = strlen(txt);
  int p = 0; //hash value for pattern
  int t = 0; //hash value for text
  int h = 1;

  // The value of h would be "pow(d, M-1)%q"
  for (int i = 0; i < pat_len - 1; i++)
    h = (h * d) % q;

  // Calculate the hash value of pattern and first
  // window of text
  for (int i = 0; i < pat_len; i++)
  {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  int j;
  // Slide the pattern over text one by one
  for (int i = 0; i <= txt_len - pat_len; i++)
  {

    // Check the hash values of current window of text
    // and pattern. If the hash values match then only
    // check for characters on by one
    if (p == t)
    {
      /* Check for characters one by one */
      for (j = 0; j < pat_len; j++)
      {
        if (txt[i + j] != pat[j])
          break;
      }

      // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
      if (j == pat_len)
        cout << "Pattern found at index " << i << endl;
    }

    // Calculate hash value for next window of text: Remove
    // leading digit, add trailing digit
    if (i < txt_len - pat_len)
    {
      t = (d * (t - txt[i] * h) + txt[i + pat_len]) % q;

      // We might get negative value of t, converting it
      // to positive
      if (t < 0)
        t = (t + q);
    }
  }
}

int main()
{
  char txt[] = "GEEKS FOR GEEKS";
  char pat[] = "GEEK";

  // A prime number
  int q = 101; //program fails to detect the second pattern with val 10e9+7

  // Function Call
  search(pat, txt, q);
  return 0;
}
