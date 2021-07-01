#include <bits/stdc++.h>
using namespace std;

void printUtil(vector<vector<string>> &arr, int m, int n, string output[])
{
  output[m] = arr[m][n];

  if (m == arr.size() - 1)
  {
    for (int i = 0; i < arr.size(); i++)
      cout << output[i] << " ";
    cout << endl;
    return;
  }

  for (int i = 0; i < arr[m].size(); i++)
    printUtil(arr, m + 1, i, output);
}

void print(vector<vector<string>> &arr)
{
  string output[arr.size()];

  for (int i = 0; i < arr[0].size(); i++)
    printUtil(arr, 0, i, output);
}

int main()
{
  vector<vector<string>> arr{{"you", "we"},
                             {"have", "are"},
                             {"sleep", "eat", "drink"}};
  print(arr);
}
