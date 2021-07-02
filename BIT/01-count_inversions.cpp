/*Solution using BIT of size Θ(maxElement):

Approach: Traverse through the array and for every index find the number of smaller elements on its right side of the array. This can be done using BIT. Sum up the counts for all indexes in the array and print the sum.
Background on BIT:
BIT basically supports two operations for an array arr[] of size n:
Sum of elements till arr[i] in O(Log n) time.
Update an array element in O(Log n) time.
BIT is implemented using an array and works in form of trees. Note that there are two ways of looking at BIT as a tree.
The sum operation where parent of index x is “x – (x & -x)”.
The update operation where parent of index x is “x + (x & -x)”.
Algorithm:
Create a BIT, to find the count of the smaller elements in the BIT for a given number and also a variable result = 0.
Traverse the array from end to start.
For every index check how many numbers less than the current element are present in BIT and add it to the result
To get the count of smaller elements, getSum() of BIT is used.
In his basic idea, BIT is represented as an array of size equal to maximum element plus one. So that elements can be used as an index.
After that we add the current element to the BIT[] by doing an update operation that updates the count of the current element from 0 to 1, and therefore updates ancestors of the current element in BIT (See update() in BIT for details). */

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

// Returns inversion count arr[0..n-1]
int getInvCount(int arr[], int n)
{
  int invcount = 0; // Initialize result

  // Find maximum element in arr[]
  int maxElement = 0;
  for (int i = 0; i < n; i++)
    if (maxElement < arr[i])
      maxElement = arr[i];

  // Create a BIT with size equal to maxElement+1 (Extra
  // one is used so that elements can be directly be
  // used as index)
  int BIT[maxElement + 1];
  for (int i = 1; i <= maxElement; i++)
    BIT[i] = 0;

  // Traverse all elements from right.
  for (int i = n - 1; i >= 0; i--)
  {
    // Get count of elements smaller than arr[i]
    invcount += getSum(BIT, arr[i] - 1);

    // Add current element to BIT
    updateBIT(BIT, maxElement, arr[i], 1);
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
/*Complexity Analysis:
Time Complexity :- The update function and getSum function runs for O(log(maximumelement)). The getSum function has to be run for every element in the array. So overall time complexity is : O(nlog(maximumelement)).
Auxiliary space : O(maxElement), space required for the BIT is an array of the size of the largest element.*/
