// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
  int pat_len = strlen(pat);
  int txt_len = strlen(txt);

  // create lps[] that will hold the longest prefix suffix
  // values for pattern
  int lps[pat_len];

  // Preprocess the pattern (calculate lps[] array)
  computeLPSArray(pat, pat_len, lps);

  int i = 0; // index for txt[]
  int j = 0; // index for pat[]
  while (i < txt_len)
  {
    if (pat[j] == txt[i])
    {
      j++;
      i++;
    }

    if (j == pat_len)
    {
      printf("Found pattern at index %d ", i - j);
      j = lps[j - 1];
    }

    // mismatch after j matches
    else if (i < txt_len && pat[j] != txt[i])
    {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int pat_len, int *lps)
{
  // length of the previous longest prefix suffix
  int len = 0;

  lps[0] = 0; // lps[0] is always 0

  // the loop calculates lps[i] for i = 1 to M-1
  int i = 1;
  while (i < pat_len)
  {
    if (pat[i] == pat[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else // (pat[i] != pat[len])
    {
      // This is tricky. Consider the example.
      // AAACAAAA and i = 7. The idea is similar
      // to search step.
      if (len != 0)
      {
        len = lps[len - 1];

        // Also, note that we do not increment
        // i here
      }
      else // if (len == 0)
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

// Driver program to test above function
int main()
{
  char txt[] = "ABABDABACDABABCABAB";
  char pat[] = "ABABCABAB";
  KMPSearch(pat, txt);
  return 0;
}
