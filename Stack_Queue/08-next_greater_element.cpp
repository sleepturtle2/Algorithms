// A Stack based C++ program to find next
// greater element for all array elements
// in same order as input.
#include <bits/stdc++.h>
 
using namespace std;
 
/* prints element and res pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for (int i = n - 1; i >= 0; i--) {
        /* if stack is not empty, then
        pop an element from stack.
        If the popped element is smaller
        than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}
// Driver Code
int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    printNGE(arr, n);
    return 0;
}