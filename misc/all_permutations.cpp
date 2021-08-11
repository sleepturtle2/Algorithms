#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str = "ABCCBB";

  //next permutation will only work as long as there is a lexicographically higher combination possible
  //to generate all combinations, sort the string and then use next_permutation

  //alternative is to make a copy of the string
  //use prev_permutation on one copy and next_permutation on the other
  do
  {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end()));

  int a[] = {1, 4, 5, 5};
  int n = sizeof(a) / sizeof(a[0]);
  do
  {
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
  } while (next_permutation(a, a + n));
}
