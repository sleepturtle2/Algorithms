/*
Next Smaller Element
Difficulty Level : Medium
Last Updated : 31 Aug, 2021
Given an array, print the Next Smaller Element (NSE) for every element. The Smaller smaller Element for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider next smaller element as -1. 
Examples: 
a) For any array, rightmost element always has next smaller element as -1. 
b) For an array which is sorted in increasing order, all elements have next smaller element as -1. 
c) For the input array [4, 8, 5, 2, 25}, the next smaller elements for each element are as follows.
This problem is similar to next greater element. Here we maintain items in increasing order in the stack (instead of decreasing in next greater element problem).
1) Push the first element to stack. 
2) Pick rest of the elements one by one and follow following steps in loop. 
….a) Mark the current element as next. 
….b) If stack is not empty, then pop an element from stack and compare it with next. 
….c) If next is smaller than the popped element, then next is the next smaller element for the popped element. 
….d) Keep popping from the stack while the popped element is greater than next. next becomes the next smaller element for all such popped elements 
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.
*/

// A Stack based C++ program to find next
// smaller element for all array elements.
#include <bits/stdc++.h>
 
using namespace std;
 
/* prints element and NSE pair for all
elements of arr[] of size n */
void printNSE(int arr[], int n)
{
    stack<int> s;
 
    /* push the first element to stack */
    s.push(arr[0]);
 
    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
 
        /* if stack is not empty, then
       pop an element from stack.
       If the popped element is greater
       than next, then
    a) print the pair
    b) keep popping while elements are
    greater and stack is not empty */
        while (s.empty() == false && s.top() > arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
 
        /* push next to stack so that we can find
    next smaller for it */
        s.push(arr[i]);
    }
 
    /* After iterating over the loop, the remaining
  elements in stack do not have the next smaller
  element, so print -1 for them */
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}
/*
Time Complexity: O(n). The worst case occurs when all elements are sorted in increasing order. If elements are sorted in increasing order, then every element is processed at most 4 times. 
a) Initially pushed to the stack. 
b) Popped from the stack when next element is being processed. 
c) Pushed back to the stack because next element is smaller. 
d) Popped from the stack in step 3 of algo.
*/
