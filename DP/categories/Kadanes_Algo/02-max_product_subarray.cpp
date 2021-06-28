#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &a)
{
  int len = a.size();
  if (len == 1)
    return a[0];

  int max_i = a[0]; //maximum including the current index
  int min_i = a[0]; // minimum including the current index

  int max_global = max_i;

  for (int i = 1; i < len; i++)
  {
    int prod1 = max_i * a[i];
    int prod2 = min_i * a[i];
    max_i = max(a[i], max(prod1, prod2));
    min_i = min(a[i], min(prod1, prod2));

    max_global = max(max_global, max_i);
    //cout<<max_i<<" "<<min_i<<" "<<max_global<<endl;
  }
  return max_global;
}

int main()
{
  vector<int> nums = {2, 3, -2, 4};
  cout << maxProduct(nums) << endl;
}
