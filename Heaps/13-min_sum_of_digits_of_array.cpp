
/*Minimum sum of two numbers formed from digits of an array

Given an array of digits (values are from 0 to 9), find the minimum possible 
sum of two numbers formed from digits of the array. All digits of given array 
must be used to form the two numbers. 
Examples : 
 

Input: [6, 8, 4, 5, 2, 3]
Output: 604
The minimum sum is formed by numbers 
358 and 246

Input: [5, 3, 0, 7, 4]
Output: 82
The minimum sum is formed by numbers 
35 and 047 

A minimum number will be formed from set of digits when smallest digit appears 
at most significant position and next smallest digit appears at next most 
significant position ans so on..

The idea is to sort the array in increasing order and build two numbers by 
alternating picking digits from the array. So first number is formed by digits 
present in odd positions in the array and second number is formed by digits 
from even positions in the array. Finally, we return the sum of first and 
second number.*/

// C++ program to find minimum sum of two numbers
// formed from digits of the array.
#include <bits/stdc++.h>
using namespace std;
 
// Function to find and return minimum sum of
// two numbers formed from digits of the array.
int solve(int arr[], int n)
{
    // sort the array
    sort(arr, arr + n);
 
    // let two numbers be a and b
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        // fill a and b with every alternate digit
        // of input array
        if (i & 1)
            a = a*10 + arr[i];
        else
            b = b*10 + arr[i];
    }
 
    // return the sum
    return a + b;
}
 
// Driver code
int main()
{
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum is " << solve(arr, n)<<endl;
    return 0;
}