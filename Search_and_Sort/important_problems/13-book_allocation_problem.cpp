/*Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. */
/*
The idea is to use Binary Search. We fix a value for the number of pages as mid of current minimum and maximum. We initialize minimum and maximum as 0 and sum-of-all-pages respectively. If a current mid can be a solution, then we search on the lower half, else we search in higher half.
Now the question arises, how to check if a mid value is feasible or not? Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. To do this, we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.
Below is an implementation of above idea.
 */
#include <bits/stdc++.h>
using namespace std;

// Utility function to check if current minimum value
// is feasible or not.
bool isPossible(int arr[], int n, int m, int curr_min)
{
  int studentsRequired = 1;
  int curr_sum = 0;

  // iterate over all books
  for (int i = 0; i < n; i++)
  {
    // check if current number of pages are greater
    // than curr_min that means we will get the result
    // after mid no. of pages
    if (arr[i] > curr_min)
      return false;

    // count how many students are required
    // to distribute curr_min pages
    if (curr_sum + arr[i] > curr_min)
    {
      // increment student count
      studentsRequired++;

      // update curr_sum
      curr_sum = arr[i];

      // if students required becomes greater
      // than given no. of students,return false
      if (studentsRequired > m)
        return false;
    }

    // else update curr_sum
    else
      curr_sum += arr[i];
  }
  return true;
}

// function to find minimum pages
int findPages(int arr[], int n, int m)
{
  long long sum = 0;

  // return -1 if no. of books is less than
  // no. of students
  if (n < m)
    return -1;

  // Count total number of pages
  for (int i = 0; i < n; i++)
    sum += arr[i];

  // initialize start as 0 pages and end as
  // total pages
  int start = 0, end = sum;
  int result = INT_MAX;

  // traverse until start <= end
  while (start <= end)
  {
    // check if it is possible to distribute
    // books by using mid as current minimum
    int mid = (start + end) / 2;
    if (isPossible(arr, n, m, mid))
    {
      // update result to current distribution
      // as it's the best we have found till now.
      result = mid;

      // as we are finding minimum and books
      // are sorted so reduce end = mid -1
      // that means
      end = mid - 1;
    }

    else
      // if not possible means pages should be
      // increased so update start = mid + 1
      start = mid + 1;
  }

  // at-last return minimum no. of  pages
  return result;
}

// Drivers code
int main()
{
  //Number of pages in books
  int arr[] = {12, 34, 67, 90};
  int n = sizeof arr / sizeof arr[0];
  int m = 2; //No. of students

  cout << "Minimum number of pages = "
       << findPages(arr, n, m) << endl;
  return 0;
}
