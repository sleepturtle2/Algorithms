/*Approach: Traverse through the array and for every index find the number of smaller elements on its right side of the array. This can be done using BIT. Sum up the counts for all indexes in the array and print the sum. The approach remains the same but the problem with the previous approach is that it doesn’t work for negative numbers as the index cannot be negative. The idea is to convert the given array to an array with values from 1 to n and the relative order of smaller and greater elements remains the same.
Example:-
Algorithm:
Create a BIT, to find the count of the smaller elements in the BIT for a given number and also a variable result = 0.
The previous solution does not work for arrays containing negative elements. So, convert the array into an array containing relative numbering of elements,i.e make a copy of the original array and then sort the copy of the array and replace the elements in the original array with the indices of the same elements in the sorted array.
For example, if the array is {-3, 2, 0} then the array gets converted to {1, 3, 2}
Traverse the array from end to start.
For every index check how many numbers less than the current element are present in BIT and add it to the result*/
#include <bits/stdc++.h>
using namespace std;

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
  int sum = 0; // Initialize result

  // Traverse ancestors of BITree[index]
  while (index > 0)
  {
    // Add current element of BITree to sum
    sum += BITree[index];

    // Move index to parent node in getSum View
    index -= index & (-index);
  }
  return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
  // Traverse all ancestors and add 'val'
  while (index <= n)
  {
    // Add 'val' to current node of BI Tree
    BITree[index] += val;

    // Update index to that of parent in update View
    index += index & (-index);
  }
}

// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements remains
// same.  For example, {7, -90, 100, 1} is converted to
// {3, 1, 4 ,2 }
void convert(int arr[], int n)
{
  // Create a copy of arrp[] in temp and sort the temp array
  // in increasing order
  int temp[n];
  for (int i = 0; i < n; i++)
    temp[i] = arr[i];
  sort(temp, temp + n);

  // Traverse all array elements
  for (int i = 0; i < n; i++)
  {
    // lower_bound() Returns pointer to the first element
    // greater than or equal to arr[i]
    arr[i] = lower_bound(temp, temp + n, arr[i]) - temp + 1;
  }
}

// Returns inversion count arr[0..n-1]
int getInvCount(int arr[], int n)
{
  int invcount = 0; // Initialize result

  // Convert arr[] to an array with values from 1 to n and
  // relative order of smaller and greater elements remains
  // same.  For example, {7, -90, 100, 1} is converted to
  //  {3, 1, 4 ,2 }
  convert(arr, n);

  // Create a BIT with size equal to maxElement+1 (Extra
  // one is used so that elements can be directly be
  // used as index)
  int BIT[n + 1];
  for (int i = 1; i <= n; i++)
    BIT[i] = 0;

  // Traverse all elements from right.
  for (int i = n - 1; i >= 0; i--)
  {
    // Get count of elements smaller than arr[i]
    invcount += getSum(BIT, arr[i] - 1);

    // Add current element to BIT
    updateBIT(BIT, n, arr[i], 1);
  }

  return invcount;
}

// Driver program
int main()
{
  int arr[] = {8, 4, 2, 1};
  int n = sizeof(arr) / sizeof(int);
  cout << "Number of inversions are : " << getInvCount(arr, n);
  return 0;
}

/*Time Complexity: The update function and getSum function runs for O(log(n)). The getSum function has to be run for every element in the array. So overall time complexity is O(nlog(n)).
Auxiliary Space: O(n).
Space required for the BIT is an array of the size n.*/
