/*
Approach: Let the input array be A[].

Create an auxiliary array aux[] and store sum of all possible pairs in aux[]. The size of aux[] will be n*(n-1)/2 where n is the size of A[].
Sort the auxiliary array aux[].
Now the problem reduces to find two elements in aux[] with sum equal to X. We can use method 1 of this post to find the two elements efficiently. There is following important point to note though:
An element of aux[] represents a pair from A[]. While picking two elements from aux[], we must check whether the two elements have an element of A[] in common. For example, if first element sum of A[1] and A[2], and second element is sum of A[2] and A[4], then these two elements of aux[] don’t represent four distinct elements of input array A[].*/
// C++ program to find 4 elements
// with given sum
#include <bits/stdc++.h>
using namespace std;

// The following structure is needed
// to store pair sums in aux[]
class pairSum
{
public:
  // index (int A[]) of first element in pair
  int first;

  // index of second element in pair
  int sec;

  // sum of the pair
  int sum;
};

// Following function is needed
// for library function qsort()
int compare(const void *a, const void *b)
{
  return ((*(pairSum *)a).sum - (*(pairSum *)b).sum);
}

// Function to check if two given pairs
// have any common element or not
bool noCommon(pairSum a, pairSum b)
{
  if (a.first == b.first || a.first == b.sec || a.sec == b.first || a.sec == b.sec)
    return false;
  return true;
}

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
  int i, j;

  // Create an auxiliary array
  // to store all pair sums
  int size = (n * (n - 1)) / 2;
  pairSum aux[size];

  // Generate all possible pairs
  // from A[] and store sums
  // of all possible pairs in aux[]
  int k = 0;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      aux[k].sum = arr[i] + arr[j];
      aux[k].first = i;
      aux[k].sec = j;
      k++;
    }
  }

  // Sort the aux[] array using
  // library function for sorting
  qsort(aux, size, sizeof(aux[0]), compare);

  // Now start two index variables
  // from two corners of array
  // and move them toward each other.
  i = 0;
  j = size - 1;
  while (i < size && j >= 0)
  {
    if ((aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j]))
    {
      cout << arr[aux[i].first] << ", "
           << arr[aux[i].sec] << ", "
           << arr[aux[j].first] << ", "
           << arr[aux[j].sec] << endl;
      return;
    }
    else if (aux[i].sum + aux[j].sum < X)
      i++;
    else
      j--;
  }
}

// Driver code
int main()
{
  int arr[] = {10, 20, 30, 40, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int X = 91;

  // Function Call
  findFourElements(arr, n, X);
  return 0;
}
/*
Complexity Analysis:

Time complexity: O(n^2Logn).
The step 1 takes O(n^2) time. The second step is sorting an array of size O(n^2). Sorting can be done in O(n^2Logn) time using merge sort or heap sort or any other O(nLogn) algorithm. The third step takes O(n^2) time. So overall complexity is O(n^2Logn).
Auxiliary Space: O(n^2).
The size of the auxiliary array is O(n^2). The big size of the auxiliary array can be a concern in this method.
*/
