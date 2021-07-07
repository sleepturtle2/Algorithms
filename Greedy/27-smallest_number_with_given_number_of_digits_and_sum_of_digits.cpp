/*
How to find the smallest number with given digit sum s and number of digits d?
Examples :


Input  : s = 9, d = 2
Output : 18
There are many other possible numbers
like 45, 54, 90, etc with sum of digits
as 9 and number of digits as 2. The
smallest of them is 18.

Input  : s = 20, d = 3
Output : 299

A Simple Solution is to consider all m digit numbers and keep track of minimum number with digit sum as s. A close upper bound on time complexity of this solution is O(10m).
There is a Greedy approach to solve the problem. The idea is to one by one fill all digits from rightmost to leftmost (or from least significant digit to most significant).
We initially deduct 1 from sum s so that we have smallest digit at the end. After deducting 1, we apply greedy approach. We compare remaining sum with 9, if remaining sum is more than 9, we put 9 at the current position, else we put the remaining sum. Since we fill digits from right to left, we put the highest digits on the right side. Below is implementation of the idea.
*/

#include <iostream>
using namespace std;

// Prints the smallest possible number with digit sum 's'
// and 'm' number of digits.
void findSmallest(int m, int s)
{
  // If sum of digits is 0, then a number is possible
  // only if number of digits is 1.
  if (s == 0)
  {
    (m == 1) ? cout << "Smallest number is " << 0
             : cout << "Not possible";
    return;
  }

  // Sum greater than the maximum possible sum.
  if (s > 9 * m)
  {
    cout << "Not possible";
    return;
  }

  // Create an array to store digits of result
  int res[m];

  // deduct sum by one to account for cases later
  // (There must be 1 left for the most significant
  //  digit)
  s -= 1;

  // Fill last m-1 digits (from right to left)
  for (int i = m - 1; i > 0; i--)
  {
    // If sum is still greater than 9,
    // digit must be 9.
    if (s > 9)
    {
      res[i] = 9;
      s -= 9;
    }
    else
    {
      res[i] = s;
      s = 0;
    }
  }

  // Whatever is left should be the most significant
  // digit.
  res[0] = s + 1; // The initially subtracted 1 is
                  // incorporated here.

  cout << "Smallest number is ";
  for (int i = 0; i < m; i++)
    cout << res[i];
}

// Driver code
int main()
{
  int s = 9, m = 2;
  findSmallest(m, s);
  return 0;
}
/*
Output :

Smallest number is 18
Time Complexity of this solution is O(m).
*/
