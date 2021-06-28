#include <bits/stdc++.h>
using namespace std;

long long bin_pow_recursive(long long a, long long b)
{
  if (b == 0)
    return 1;

  long long res = bin_pow_recursive(a, b / 2);
  if (b % 2) //odd
    return res * res * a;
  else
    return res * res;
}

long long bin_pow_iterative(long long a, long long b)
{
  long long res = 1;
  while (b > 0)
  {
    if (b & 1) //odd
      res = res * a;
    a = a * a;
    b >>= 1; //b= b/2;
  }
  return res;
}

long long bin_pow_mod(long long a, long long b, long long m)
{
  a %= m;
  long long res = 1;
  while (b > 0)
  {
    if (b & 1) //odd
      res = res * a % m;
    a = a * a % m;
    b >>= 1; //b= b/2;
  }
  return res;
}

int main()
{
  cout << bin_pow_recursive(2, 10) << endl;
  cout << bin_pow_iterative(2, 10) << endl;
  cout << bin_pow_mod(2, 10, 100) << endl;
}
