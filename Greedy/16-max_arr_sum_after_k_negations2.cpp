/*
Approach 2 (Using Sort):
This approach is somewhat better than the above-discussed method. In this method, we will first sort the given array using the java in-built sort function which has the worst running time complexity of O(nlogn).
Then for a given value of k we will continue to iterate through the array till k remains greater than 0, If the value of the array at any index is less than 0 we will change its sign and decrement k by 1.
If we find a 0 in the array we will immediately set k equal to 0 to maximize our result.
In some cases, if we have all the values in an array greater than 0 we will change the sign of positive values, as our array is already sorted we will be changing signs of lower values present in the array which will eventually maximize our sum.*/

#include <bits/stdc++.h>

using namespace std;

int sol(int arr[], int n, int k)
{
  int sum = 0;
  int i = 0;

  // Sorting given array using in-built
  // sort function
  sort(arr, arr + n);
  while (k > 0)
  {
    // If we find a 0 in our
    // sorted array, we stop
    if (arr[i] >= 0)
      k = 0;
    else
    {
      arr[i] = (-1) * arr[i];
      k = k - 1;
    }
    i++;
  }

  // Calculating sum
  for (int j = 0; j < n; j++)
  {
    sum += arr[j];
  }
  return sum;
}

// Driver code
int main()
{
  int arr[] = {-2, 0, 5, -1, 2};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << sol(arr, n, 4) << endl;

  return 0;
}
/*
Output
10
Time Complexity: O(n*logn)
Auxiliary Space: O(1)
*/
