/*Given two arrays S[] and E[] of size N denoting starting and closing time of the shops and an integer value K denoting the number of people, the task is to find out the maximum number of shops they can visit in total if they visit each shop optimally based on the following conditions:

A shop can be visited by only one person
A person cannot visit another shop if its timing collide with it
Examples:

Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Explanation: One possible solution can be that first person visits the 1st and 5th shops meanwhile second person will visit 4th and 2nd shops.

Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
Output: 3
Explanation: One possible solution can be that first person visits the 1st and 3rd shops meanwhile second person will visit 2nd shop.

Follow the steps below to solve the problem:

Initialize an array a[] of pairs and store the pair {S[i], E[i]} for each index i.

Sort the array a[] according to the ending time.

Initialize a multiset st to store the persons with ending time of shop they are currently visiting.

Initialize a variable ans with 0 to store the final result.

Traverse each pair of array a[],
  If a person is available i.e a[i].first is greater than or equal to the ending time of any person in the multiset st, then increment the count by 1 and update the ending time of that element with new a[i].second.

  Otherwise, continue checking the next pairs.
Finally, print the result as count. */

#include <bits/stdc++.h>
using namespace std;

// Comparator
bool compareBy(const pair<int, int> &a,
               const pair<int, int> &b)
{
  if (a.second != b.second)
    return a.second < b.second;
  return a.first < b.first;
}
// Function to find maximum shops
// that can be visited by K persons
int maximumShops(int *opening, int *closing,
                 int n, int k)
{
  // Store opening and closing
  // time of shops
  pair<int, int> a[n];

  for (int i = 0; i < n; i++)
  {
    a[i].first = opening[i];
    a[i].second = closing[i];
  }

  // Sort the pair of array
  sort(a, a + n, compareBy);

  // Stores the result
  int count = 0;

  // Stores current number of persons visting
  // some shop with their ending time
  multiset<int> st;

  for (int i = 0; i < n; i++)
  {

    // Check if current shop can be
    // assigned to a person who's
    // already visiting any other shop
    bool flag = false;

    if (!st.empty())
    {

      auto it = st.upper_bound(a[i].first);

      if (it != st.begin())
      {
        it--;

        // Checks if there is any person whose
        // closing time <= current shop opening
        // time
        if (*it <= a[i].first)
        {

          // Erase previous shop visited by the
          // person satisfying the condition
          st.erase(it);

          // Insert new closing time of current
          // shop for the person satisfying ṭhe
          // condition
          st.insert(a[i].second);

          // Increment the count by one
          count++;

          flag = true;
        }
      }
    }

    // In case if no person have closing
    // time <= current shop opening time
    // but there are some persons left
    if (st.size() < k && flag == false)
    {
      st.insert(a[i].second);
      count++;
    }
  }

  // Finally print the ans
  return count;
}

// Driver Code
int main()
{

  // Given starting and ending time
  int S[] = {1, 8, 3, 2, 6};
  int E[] = {5, 10, 6, 5, 9};

  // Given K and N
  int K = 2, N = sizeof(S) / sizeof(S[0]);

  // Function call
  cout << maximumShops(S, E, N, K) << endl;
}
/*
Output:
4

Time complexity: O(NlogN)
Auxiliary Space: O(N)

*/
