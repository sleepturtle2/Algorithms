#include <bits/stdc++.h>
using namespace std;

int lower_bound(int nums[], int n, int target)
{
  int low = 0;
  int high = n - 1;
  int mid;

  while (low <= high)
  {
    mid = low + (high - low) / 2;
    if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int upper_bound(int nums[], int n, int target)
{
  int low = 0;
  int high = n - 1;
  int mid;

  while (low < high)
  {
    mid = low + (high - low) / 2;
    if (nums[mid] <= target)
      low = mid + 1;
    else
      high = mid;
  }
  if (low < n - 1 && nums[low] <= target)
    low++;
  return low;
}
int main()
{
  int a[] = {2, 3, 4, 6, 7, 8};
  int n = 6;

  cout << lower_bound(a, n, 5) << " for element " << 5 << endl;
  cout << lower_bound(a, n, 4) << " for element " << 4 << endl;

  cout << upper_bound(a, n, 5) << " for element " << 5 << endl;
  cout << upper_bound(a, n, 6) << " for element " << 6 << endl;
}
