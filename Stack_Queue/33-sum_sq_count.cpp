/*
Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1, e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 2^2 = 9.
Expected Time Complexity: O(k*logn)
Examples: 
 

Input :  str = abccc, K = 1
Output :  6
We remove c to get the value as 12 + 12 + 22

Input :  str = aaab, K = 2
Output :  2

One clear observation is that we need to remove character with highest frequency. One trick is the character ma
A Simple solution is to use sorting technique through all current highest frequency reduce up to k times. For After every reduce again sort frequency array. 
A Better Solution used to Priority Queue which has to the highest element on top. 
 

Initialize empty priority queue.
Count frequency of each character and Store into temp array.
Remove K characters which have highest frequency from queue.
Finally Count Sum of square of each element and return it.

*/

// C++ program to find min sum of squares
// of characters after k removals
#include <bits/stdc++.h>
using namespace std;
 
const int MAX_CHAR = 26;
 
// Main Function to calculate min sum of
// squares of characters after k removals
int minStringValue(string str, int k)
{
    int l = str.length(); // find length of string
 
    // if K is greater than length of string
    // so reduced string will become 0
    if (k >= l)
        return 0;
 
    // Else find Frequency of each character and
    // store in an array
    int frequency[MAX_CHAR] = { 0 };
    for (int i = 0; i < l; i++)
        frequency[str[i] - 'a']++;
 
    // Push each char frequency into a priority_queue
    priority_queue<int> q;
    for (int i = 0; i < MAX_CHAR; i++)
        q.push(frequency[i]);
 
    // Removal of K characters
    while (k--) {
        // Get top element in priority_queue,
        // remove it. Decrement by 1 and again
        // push into priority_queue
        int temp = q.top();
        q.pop();
        temp = temp - 1;
        q.push(temp);
    }
 
    // After removal of K characters find sum
    // of squares of string Value
    int result = 0; // Initialize result
    while (!q.empty()) {
        int temp = q.top();
        result += temp * temp;
        q.pop();
    }
 
    return result;
}
 
// Driver Code
int main()
{
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;
 
    str = "aaab"; // Input 2
    k = 2;
    cout << minStringValue(str, k);
 
    return 0;
}