#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

//complete binary tree
// i is parent, 2*i+1 is left child, 2*i+2 is right child

//inorder traversal of bin search tree is sorted
//problem is basically to find the minimum number of swaps to sort an array

void inorder(int a[], std::vector<int> &v,
             int n, int index)
{
  // if index is greater or equal to vector size
  if (index >= n)
    return;
  inorder(a, v, n, 2 * index + 1); //left child

  // push elements in vector
  v.push_back(a[index]);
  inorder(a, v, n, 2 * index + 2); //right child
}

int minSwaps_method1(vector<int> &v)
{
  vector<pair<int, int>> t(v.size()); //(arr element, position)
  int ans = 0;
  for (int i = 0; i < v.size(); i++)
    t[i].first = v[i], t[i].second = i;

  sort(t.begin(), t.end()); //sort by array elements
  for (int i = 0; i < t.size(); i++)
  {
    // second element is equal to i
    if (i == t[i].second) //element already at the correct position
      continue;
    else
    {
      // swaping of elements
      swap(t[i].first, t[t[i].second].first);
      swap(t[i].second, t[t[i].second].second);
    }

    // Second is not equal to i
    if (i != t[i].second) //keep swapping till t[i].second == i. correct position only then
      --i;
    ans++;
  }
  return ans;
}

int minSwaps_method2(vector<int> &v)
{
  vector<pair<int, int>> arrPos(v.size());
  for (int i = 0; i < v.size(); i++)
  {
    arrPos[i].first = v[i];
    arrPos[i].second = i;
  }

  sort(arrPos.begin(), arrPos.end()); //sort by first element

  vector<bool> visited(v.size()); //to keep track of visited elements, to detect end of cycle

  int total_swaps = 0;

  for (int i = 0; i < v.size(); i++)
  {
    //ignore if element has been visited and corrected or if element already at the correct position
    if (visited[i] || arrPos[i].second == i)
      continue;

    int j = i;
    int cycle_length = 0;
    while (!visited[j])
    {
      visited[j] = true;
      cycle_length++;
      j = arrPos[j].second;
    }
    if (cycle_length > 0)
      total_swaps += cycle_length - 1;
  }
  return total_swaps;
}

void swap(vector<int> &arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
//straightforward method. uses hash table
int minSwaps_method3(vector<int> &v)
{
  unordered_map<int, int> map;
  vector<int> temp = v;
  sort(temp.begin(), temp.end()); //o(nlogn)

  for (int i = 0; i < v.size(); i++)
    map[v[i]] = i;

  int total_swaps = 0;
  for (int i = 0; i < v.size(); i++)
  {
    //check whether current element is at right position
    if (v[i] != temp[i])
    {
      total_swaps++;
      int init = v[i];

      //swap with correct element
      swap(v, i, map[temp[i]]);

      //update indexes accordingly
      map[init] = map[temp[i]];
      map[temp[i]] = i;
    }
  }
  return total_swaps;
}

int main()
{
  int a[] = {5, 6, 7, 8, 9, 10, 11};
  int n = sizeof(a) / sizeof(a[0]);
  vector<int> v;
  inorder(a, v, n, 0);
  cout << minSwaps_method1(v) << endl; //o(nlogn)
  cout << minSwaps_method2(v) << endl; //o(nlogn)
  cout << minSwaps_method3(v) << endl; //using hash o(nlogn)
  node *root = tree();

  return 0;
}
