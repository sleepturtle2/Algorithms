/*
Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

Examples:  

Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
Output : -1 -1 -7 -15 -15 0

It is a variation of the problem of Sliding Window Maximum. 
We create a Dequeue, Di of capacity k, that stores only useful elements of the 
current window of k elements. An element is useful if it is in the current 
window and it is a negative integer. We process all array elements one by one 
and maintain Di to contain useful elements of current window and these useful 
elements are all negative integers. For a particular window, if Di is not 
empty then the element at front of the Di is the first negative integer for 
that window, else that window does not contain a negative integer.
*/

// C++ implementation to find the first negative
// integer in every window of size k
#include <bits/stdc++.h>
 
using namespace std;
  
// function to find the first negative
// integer in every window of size k
void printFirstNegativeInteger(int arr[], int n, int k)
{
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<int>  Di;
  
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);
     
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; i++)
    {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
            cout << arr[Di.front()] << " ";
         
        // else the window does not have a
        // negative integer
        else
            cout << "0" << " ";
  
        // Remove the elements which are out of this window
        while ( (!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front();  // Remove from front of queue
  
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);
    }
  
    // Print the first negative
    // integer of last window
    if (!Di.empty())
           cout << arr[Di.front()] << " ";
    else
        cout << "0" << " ";      
     
}
  
// Driver program to test above functions
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}

/*
Time Complexity: O(n) 
Auxiliary Space: O(k)

Optimized Approach:: It is also possible to accomplish this with constant space. The idea is to have a variable firstNegativeIndex to keep track of the first negative element in the k sized window. At every iteration, we skip the elements which no longer fall under the current k size window (firstNegativeIndex <= i – k) as well as the positive elements. 
*/

// C++ code for First negative integer
// in every window of size k
#include <iostream>
using namespace std;
 
void printFirstNegativeInteger(int arr[], int k, int n)
{
    int firstNegativeIndex = 0;
    int firstNegativeElement;
     
    
    for(int i = k - 1; i < n; i++)
    {
       
        // skip out of window and positive elements
        while((firstNegativeIndex < i ) &&
              (firstNegativeIndex <= i - k ||
               arr[firstNegativeIndex] > 0))
        {
            firstNegativeIndex ++;
        }
         
        // check if a negative element is found, otherwise use 0
        if(arr[firstNegativeIndex] < 0)
        {
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else
        {
            firstNegativeElement = 0;
        }
        cout<<firstNegativeElement << " ";
    }
     
}
 
// Driver code
int main()
{
     int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28};
      int n = sizeof(arr)/sizeof(arr[0]);
     int k = 3;
     printFirstNegativeInteger(arr, k, n);   
}
/*
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/