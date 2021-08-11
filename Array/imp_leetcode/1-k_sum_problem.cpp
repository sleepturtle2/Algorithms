/*
Given an array nums of n integers, return an array of all the unique k elements [nums[a], nums[b], nums[c], nums[d] ... k elements] such that:

0 <= a, b, c, d ...  < n
a, b, c, d... are not distinct. (handle duplicates)

nums[a] + nums[b] + nums[c] + nums[d] + ... kth element == target
You may return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void kSum(vector<int> &nums, int target, int k, int start, vector<vector<int>> &res, vector<int> &curr, int sm)
  {
    if (k == 2)
    {
      int i = start, j = nums.size() - 1;
      target -= sm;
      while (i < j)
      {
        if (nums[i] + nums[j] < target)
          i++;
        else if (nums[i] + nums[j] > target)
          j--;
        else
        {
          curr[curr.size() - 2] = nums[i];
          curr[curr.size() - 1] = nums[j];
          res.push_back(curr);
          while (i + 1 < j && nums[i] == nums[i + 1])
            i++;
          i++;
          while (i < j - 1 && nums[j] == nums[j - 1])
            j--;
          j--;
        }
      }
      return;
    }
    for (int i = start; i + k - 1 < nums.size(); i++)
    {
      curr[curr.size() - k] = nums[i];
      kSum(nums, target, k - 1, i + 1, res, curr, sm + nums[i]);
      while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        i++;
    }
  }

  inline vector<vector<int>> kSumWrapper(vector<int> &nums, int target, int k)
  {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> curr(k, 0);
    kSum(nums, target, k, 0, res, curr, 0);
    return res;
  }

  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    return kSumWrapper(nums, target, 4);
  }
};
