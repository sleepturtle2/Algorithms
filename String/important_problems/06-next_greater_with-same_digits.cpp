/*Following are few observations about the next greater number.
1) If all digits sorted in descending order, then output is always “Not Possible”. For example, 4321.
2) If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234.
3) For other cases, we need to process the number from rightmost side (why? because we need to find the smallest of all greater numbers)

You can now try developing an algorithm yourself.
Following is the algorithm for finding the next greater number.
I) Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously traversed digit. For example, if the input number is “534976”, we stop at 4 because 4 is smaller than next digit 9. If we do not find such a digit, then output is “Not Possible”.

II) Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’. For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.



III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to ‘d’ to the end of number. The number that we get after sorting is the output. For above example, we sort digits in bold 536974. We get “536479” which is the next greater number for input 534976.*/
// C++ program to find the smallest number which greater than a given number
// and has same set of digits as given number
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Utility function to swap two digits
void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

// Given a number as a char array number[], this function finds the
// next greater number.  It modifies the same array to store the result
void findNext(char number[], int n)
{
  int i, j;

  // I) Start from the right most digit and find the first digit that is
  // smaller than the digit next to it.
  for (i = n - 1; i > 0; i--)
    if (number[i] > number[i - 1])
      break;

  // If no such digit is found, then all digits are in descending order
  // means there cannot be a greater number with same set of digits
  if (i == 0)
  {
    cout << "Next number is not possible";
    return;
  }

  // II) Find the smallest digit on right side of (i-1)'th digit that is
  // greater than number[i-1]
  int x = number[i - 1], smallest = i;
  for (j = i + 1; j < n; j++)
    if (number[j] > x && number[j] < number[smallest])
      smallest = j;

  // III) Swap the above found smallest digit with number[i-1]
  swap(&number[smallest], &number[i - 1]);

  // IV) Sort the digits after (i-1) in ascending order
  sort(number + i, number + n);

  cout << "Next number with same set of digits is " << number;

  return;
}

// Driver program to test above function
int main()
{
  char digits[] = "534976";
  int n = strlen(digits);
  findNext(digits, n);
  return 0;
}
//o(nlogn)
