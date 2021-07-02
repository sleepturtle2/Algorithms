//Given n and q, i.e, the number of ranges and number of queries, find the kth smallest element for each query (assume k>1).Print the value of kth smallest element if it exists, else print -1.
/*The idea is to first Prerequisite : Merge Overlapping Intervals and keep all intervals sorted in ascending order of start time. After merging in an array merged[], we use linear search to find kth smallest element.*/
#include <bits/stdc++.h>
using namespace std;

// Structure to store the
// start and end point
struct Interval
{
  int s;
  int e;
};

// Comparison function for sorting
bool comp(Interval a, Interval b)
{
  return a.s < b.s;
}

// Function to find Kth smallest number in a vector
// of merged intervals
int kthSmallestNum(vector<Interval> merged, int k)
{
  int n = merged.size();

  // Traverse merged[] to find
  // Kth smallest element using Linear search.
  for (int j = 0; j < n; j++)
  {
    if (k <= abs(merged[j].e -
                 merged[j].s + 1))
      return (merged[j].s + k - 1);

    k = k - abs(merged[j].e -
                merged[j].s + 1);
  }

  if (k)
    return -1;
}

// To combined both type of ranges,
// overlapping as well as non-overlapping.
void mergeIntervals(vector<Interval> &merged,
                    Interval arr[], int n)
{
  // Sorting intervals according to start
  // time
  sort(arr, arr + n, comp);

  // Merging all intervals into merged
  merged.push_back(arr[0]);
  for (int i = 1; i < n; i++)
  {
    // To check if starting point of next
    // range is lying between the previous
    // range and ending point of next range
    // is greater than the Ending point
    // of previous range then update ending
    // point of previous range by ending
    // point of next range.
    Interval prev = merged.back();
    Interval curr = arr[i];
    if ((curr.s >= prev.s &&
         curr.s <= prev.e) &&
        (curr.e > prev.e))

      merged.back().e = curr.e;

    else
    {
      // If starting point of next range
      // is greater than the ending point
      // of previous range then store next range
      // in merged[].
      if (curr.s > prev.e)
        merged.push_back(curr);
    }
  }
}

// Driver\'s Function
int main()
{
  Interval arr[] = {{2, 6}, {4, 7}};
  int n = sizeof(arr) / sizeof(arr[0]);
  int query[] = {5, 8};
  int q = sizeof(query) / sizeof(query[0]);

  // Merge all intervals into merged[]
  vector<Interval> merged;
  mergeIntervals(merged, arr, n);

  // Processing all queries on merged
  // intervals
  for (int i = 0; i < q; i++)
    cout << kthSmallestNum(merged, query[i])
         << endl;

  return 0;
}
/*
Time Complexity : O(nlog(n))
 Auxiliary Space: O(n)
 */
