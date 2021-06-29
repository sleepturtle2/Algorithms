//https://leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k.
*/

//application of chinese remainder theorem

/*
Solution

In short, start with mod =0, then we always do mod = (mod+nums[i])%k, if mod repeats, that means between these two mod = x occurences the sum is multiple of k.
Math: c = a % k, c = b % k, so we have a % k = b % k.
Where a is the mod at i and b is the mod at j and a <= b, i < j, because all nums are non-negative. And c is the mod that repeats.
Suppose b-a=d, then we have b % k = ((a+d) % k)%k = (a%k + d%k)%k
In order to make the equation valid: a % k = (a%k + d%k)%k
d%k has to be 0, so d, the different between b and a, is a multiple of k
Example:
[23, 2, 1, 6, 7] k=9
mod = 5, 7, 8, 5 <-- at here we found it
*/
//o(n)

bool checkSubarraySum(vector<int> &nums, int k)
{

  int n = nums.size();
  unordered_map<int, int> map;
  map[0] = -1; //commenting this line fails test case [23, 2, 4, 6, 6]

  int prefix_sum = 0;

  for (int i = 0; i < n; i++)
  {
    prefix_sum += nums[i];
    if (k != 0)
      prefix_sum %= k;

    int prev;
    if (map.find(prefix_sum) != map.end())
    {
      prev = map[prefix_sum];
      if (i - prev > 1)
        return true;
    }
    else
      map[prefix_sum] = i;
  }
  return false;
}

int main()
{

  vector<int> nums = {23, 2, 6, 4, 7};
  int k = 6;
  cout << checkSubarraySum(nums, k) << endl;
}
