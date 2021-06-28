#include <bits/stdc++.h>
using namespace std;

int main()
{
  //0 only at powers of 2
  for (int i = 1; i <= 20; i++)
    cout << i << " & " << i - 1 << " = " << (i & (i - 1)) << endl;

  vector<int> bit_count(21);

  //number of set bits in bin rep of i = bit_count[i]
  for (int i = 1; i <= 20; i++)
    bit_count[i] = bit_count[i & (i - 1)] + 1;

  cout << "Count of set bits\n";
  for (int i = 0; i <= 20; i++)
    cout << i << " : " << bit_count[i] << endl;
  return 0;
}
