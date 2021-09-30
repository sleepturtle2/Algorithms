/*
Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring.

Examples: 

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()() 

Input:  ()(()))))
Output: 6
Explanation:  ()(())
1) Create an empty stack and push -1 to it. 
   The first element of the stack is used 
   to provide a base for the next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), 
   push index'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from the stack (Most of the 
      time an opening bracket)
   b) If the stack is not empty, then find the
      length of current valid substring by taking 
      the difference between the current index and
      top of the stack. If current length is more 
      than the result, then update the result.
   c) If the stack is empty, push the current index
      as a base for the next valid substring.

3) Return result.
*/

// C++ program to find length of the
// longest valid substring
#include <bits/stdc++.h>
using namespace std;
 
int findMaxLen(string str)
{
    int n = str.length();
 
    // Create a stack and push -1 as
    // initial index to it.
    stack<int> stk;
    stk.push(-1);
 
    // Initialize result
    int result = 0;
 
    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);
         
        // If closing bracket, i.e.,str[i] = ')'
        else
        {
            // Pop the previous opening
            // bracket's index
            if (!stk.empty())
            {
                stk.pop();
            }
             
            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());
 
            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else
                stk.push(i);
        }
    }
 
    return result;
}
 
// Driver code
int main()
{
    string str = "((()()";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    str = "()(()))))";
   
    // Function call
    cout << findMaxLen(str) << endl;
 
    return 0;
}