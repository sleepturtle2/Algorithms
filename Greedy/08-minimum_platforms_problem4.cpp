/*
If all the arrival and departure occur on the same day then we can use and auxiliary array to compute the required number of the platform in O(n).
Whenever an arrival occurs we increase the count of the required platform when a departure occurs we decrease the required platform at that point of time, after that, we take the cumulative sum, which would provide the required number of platform for all point of time, out of these values maximum value is our answer.*/
#include <bits/stdc++.h>
using namespace std;

int minPlatform(int arrival[], int departure[], int n)
{

  // as time range from 0 to 2359 in 24 hour clock,
  // we declare an array for values from 0 to 2360
  int platform[2361] = {0};
  int requiredPlatform = 1;
  for (int i = 0; i < n; i++)
  {

    // increment the platforms for arrival
    ++platform[arrival[i]];

    // once train departs we decrease the platform count
    --platform[departure[i] + 1];
  }

  // We are running loop till 2361 because maximum time value
  // in a day can be 23:60
  for (int i = 1; i < 2361; i++)
  {

    // taking cumulative sum of platform give us required
    // number of platform fro every minute
    platform[i] = platform[i] + platform[i - 1];
    requiredPlatform = max(requiredPlatform, platform[i]);
  }
  return requiredPlatform;
}

// Driver code
int main()
{
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Minimum Number of Platforms Required = "
       << minPlatform(arr, dep, n);
  return 0;
} /*
Output:

Minimum Number of Platforms Required = 3*/
