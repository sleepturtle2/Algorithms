// C++ program of above implementation
#include <iostream>
using namespace std;

// structure is used to return
// two values from minMax()
struct Pair
{
  int min;
  int max;
};

struct Pair getMinMax(int arr[], int low,
                      int high)
{
  struct Pair minmax, mml, mmr;
  int mid;

  // If there is only one element
  if (low == high)
  {
    minmax.max = arr[low];
    minmax.min = arr[low];
    return minmax;
  }

  // If there are two elements
  if (high == low + 1)
  {
    if (arr[low] > arr[high])
    {
      minmax.max = arr[low];
      minmax.min = arr[high];
    }
    else
    {
      minmax.max = arr[high];
      minmax.min = arr[low];
    }
    return minmax;
  }

  // If there are more than 2 elements
  mid = (low + high) / 2;
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid + 1, high);

  // Compare minimums of two parts
  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;

  // Compare maximums of two parts
  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;

  return minmax;
}

// Driver code
int main()
{
  int arr[] = {1000, 11, 445,
               1, 330, 3000};
  int arr_size = 6;

  struct Pair minmax = getMinMax(arr, 0,
                                 arr_size - 1);

  cout << "Minimum element is "
       << minmax.min << endl;
  cout << "Maximum element is "
       << minmax.max << endl;

  return 0;
}
/*
Time Complexity: O(n)

Total number of comparisons: let the number of comparisons be T(n). T(n) can be written as follows:
Algorithmic Paradigm: Divide and Conquer


  T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2
  T(2) = 1
  T(1) = 0
If n is a power of 2, then we can write T(n) as:



   T(n) = 2T(n/2) + 2
After solving the above recursion, we get

  T(n)  = 3n/2 -2
Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.*/
