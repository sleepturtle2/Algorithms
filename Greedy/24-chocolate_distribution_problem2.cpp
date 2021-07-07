/*
Given an array A[] consisting of N integers, where each value represents the marks of the ith student, the task is to find the minimum number of chocolates required to be distributed such that:

Each student should be awarded with at least one chocolate
A student with higher marks should be awarded more chocolates than his adjacent students.
Examples:

Input: A[] = {10, 30, 20}
Output: 4
Explanation : Since, 30 is larger than its adjacent, so the second student must get more chocolates. Therefore, the minimum chocolates can be distributed as {1, 2, 1} = 1 + 2 + 1 = 4

Input: A[] = {23, 14, 15, 14, 56, 29, 14}
Output: 12

Method 1:



Approach: The problem can be solved using Greedy approach. Follow the steps below to solve the problem:

Initialize array B[] of length N with 1.
Traverse from left to right from i = 1 to N – 1, updating B[i] as B[i] = B[i-1]+1 if A[i] greater the A[i-1].
After completing the above step, traverse again from right to left from i = N – 2 to 0, updating B[i] as B[i] = max(B[i], B[i+1]+1) if A[i] is greater than A[i + 1]. Otherwise, update B[i] as B[i] = max(B[i], 1).
After traversing, calculate the sum of the array B[] and print it as the minimum number of candies required.
*/

#include <iostream>
using namespace std;

// FUnction to print minimum number
// of candies required
void minChocolates(int A[], int N)
{
  int B[N];

  // Distribute 1 chocolate to each
  for (int i = 0; i < N; i++)
  {
    B[i] = 1;
  }

  // Traverse from left to right
  for (int i = 1; i < N; i++)
  {
    if (A[i] > A[i - 1])
      B[i] = B[i - 1] + 1;
    else
      B[i] = 1;
  }

  // Traverse from right to left
  for (int i = N - 2; i >= 0; i--)
  {
    if (A[i] > A[i + 1])
      B[i] = max(B[i + 1] + 1, B[i]);
    else
      B[i] = max(B[i], 1);
  }

  // Initialize sum
  int sum = 0;

  // Find total sum
  for (int i = 0; i < N; i++)
  {
    sum += B[i];
  }

  // Return sum
  cout << sum << "\n";
}

// Driver Code
int main()
{

  // Given array
  int A[] = {23, 14, 15, 14, 56, 29, 14};

  // Size of the given array
  int N = sizeof(A) / sizeof(A[0]);

  minChocolates(A, N);
}

/*
Output:
12


Time Complexity: O(N) where N is the length of the given array.
Auxiliary Space: O(N)
*/
