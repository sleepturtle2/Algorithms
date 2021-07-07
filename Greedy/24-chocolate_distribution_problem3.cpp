/*
Method 2 : Efficient approach

On careful observation, the space complexity can be reduced to O(1).

I. Observation:

Marks array will be a combination of strictly increasing, strictly decreasing or flat (value is same as both the neighbors) subarrays.
To minimize the total number of chocolates distributed, the number of chocolates received by a person and at least one of the neighbors should **differ by 1 or less.
** An exception of second observation is mentioned below

II. Distributing chocolates



Case 1: subarray is strictly increasing

If the values are strictly increasing, number of chocolates given to ith student will be one more than the number of chocolates given to (i-1)th  student (for any i > 0)

One chocolate will be given to the left most person in subarray, two the next and so on incrementally up to the person with highest marks.

For a strictly increasing subarray of length k, the chocolate distribution will be [1, 2, … , k].

Case 2 : subarray is strictly decreasing

Number of chocolates given to ith student will be one more than the chocolates given to (i+1)th  student ( for any i < n-1) with one chocolate to the rightmost person and max number to the leftmost person of the subarray.

For a strictly decreasing subarray of length k, the chocolate distribution will be [k, k-1, … ,1].

Case 3 : flat sequence

Given that a student with highest marks will be awarded more number of chocolates than neighbors. So there is no dependency if the values are equal. Minimum value will be assigned for optimal result.

One chocolate will be given to person at position i if both the adjacent values are equal to a[i] i.e, a[i-1] == a[i] == a[i+1]

For a flat subarray of length k, the chocolate distribution will be [1, 1, … ,1].

**The difference for an assigned value with both the neighbors may be greater than 1, if there is a single element in flat sequence and it lies exactly between an increasing & decreasing sequence

Transition points: The points where the trend(increasing/ decreasing/ flat nature) of subarray changes.



Peak point : Point which is end point of one increasing sequence and start point of other decreasing sequence
then value assigned will be max(k1, k2)

where k1 – value obtained from increasing sequence,

k2 – value obtained from decreasing sequence.

This point will be considered as part of either increasing or decreasing sequence only

III. Result :

 As the values in an increasing/decreasing sequence differ by 1, the number of chocolates distributed to students in a specific subarray of k elements will be  sum of k natural numbers. And the count will be k for a flat sequence as all the values are 1. The required value will be the total sum of the results of subarrays.

IV. Implementation:

Consider variables i, j initially pointing to first element, val = 1, res = 0.

After traversing through the array res gives the total number of chocolates distributed.

val while iterating index j (in increasing/flat subarray) represents the number of chocolates received by the person at j



If the subarray is increasing or a flat sequence, val is added to res; i, j are moved forward and val is updated according to next value (a[j + 1]).

If the subarray is decreasing, i is pointed to the starting point of subarray and j is moved forward till next transition point. val, res are not updated till the end of the subarray. In this case val holds the value of the peak element obtained from previous subarray. At the end of the decreasing sequence res is updated using get_sum function & val is updated to point to the number of chocolates held by the next person.

V. Example:

Input: A[ ] = {1, 2, 10, 7, 6, 4, 5, 5, 5, 6}

Output : 19

Explanation:

subarray — sequence type    —  count of chocolates

A[0-1] — increasing sequence — [1, 2]

A[2-5] — decreasing sequence — [4, 3, 2, 1]

A[5-6] — increasing sequence — [1, 2]

A[7-7] — flat sequence       — [1]

A[8-9] — increasing sequence — [1, 2]

A[2], A[9] are peak points

Chocolates distribution will be

[1, 2, 4, 3, 2, 1, 2, 1, 1, 2]

Sum of all values = 19
*/

#include <stdio.h>

// Helper function to get sum of decreasing sequence
int get_sum(int peak, int start, int end)
{
  /* peak is the value obtained at peak point
       from previous flat/increasing sequence */

  /* value obtained from decreasing sequence
     also the count of values in the sequence*/
  int count = end - start + 1;

  /* assigning max of values obtained from
     increasing and decreasing sequences */
  peak = (peak > count) ? peak : count;

  /* sum of count - 1 values & peak value
     sum of natural numbers : (n * (n + 1))/2 */
  int s = peak + (((count - 1) * count) >> 1);

  return s;
}

// Function to return minimum number of chocolates
int minChocolates(int a[], int n)
{
  int i = 0, j = 0;
  int res = 0, val = 1;

  while (j < n - 1)
  {

    if (a[j] > a[j + 1])
    {
      // decreasing sequence
      j += 1;
      continue;
    }

    if (i == j)
      // add the chocolates received by that person
      res += val;
    else
    {
      // end point of decreasing sequence
      res += get_sum(val, i, j);
      val = 1; // reset value at that index
    }

    if (a[j] < a[j + 1])
      // increasing sequence
      val += 1;
    else
      // flat sequence
      val = 1;

    j += 1;
    i = j;
  }
  // add value of chocolates at position n-1
  if (i == j)
    res += val;
  else
    res += get_sum(val, i, j);

  return res;
}

// Driver code
int main()
{

  int a[] = {5, 5, 4, 3, 2, 1};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Minimum number of chocolates = %d",
         minChocolates(a, n));
  return 0;
}
/*
Output
Minimum number of chocolates = 16
Time Complexity : O(N),  N is the length of the array

Space Complexity : O(1)
*/
