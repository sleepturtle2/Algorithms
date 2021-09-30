/*
https://www.geeksforgeeks.org/program-to-insert-an-element-at-the-bottom-of-a-stack/
Given a stack S and an integer N, the task is to insert N at the bottom of the stack.

Naive Approach: The simplest approach would be to create another stack. Follow the steps below to solve the problem:



Initialize a stack, say temp.
Keep popping from the given stack S and pushing the popped elements into temp, until the stack S becomes empty.
Push N into the stack S.
Now, keep popping from the stacktemp and push the popped elements into the stack S, until the stack temp becomes empty.

Efficient Approach: Instead of using a temporary stack, the implicit stack can be used through recursion. Follow the steps below to solve the problem: 

Define a recursion function that accepts the stack S and an integer as parameters and returns a stack.
Base case to be considered is if the stack is empty. For this scenario, push N into the stack and return it.
Otherwise, remove the top element of S and store it in a variable, say X.
Recurse again using the new stack
Push X into S.
*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Recursive function to use implicit stack
// to insert an element at the bottom of stack
stack<int> recur(stack<int> S, int N)
{
    // If stack is empty
    if (S.empty())
        S.push(N);
 
    else {
 
        // Stores the top element
        int X = S.top();
 
        // Pop the top element
        S.pop();
 
        // Recurse with remaining elements
        S = recur(S, N);
 
        // Push the previous
        // top element again
        S.push(X);
    }
    return S;
}
 
// Function to insert an element
// at the bottom of stack
void insertToBottom(
    stack<int> S, int N)
{
 
    // Recursively insert
    // N at the bottom of S
    S = recur(S, N);
 
    // Print the stack S
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}
 
// Driver Code
int main()
{
    // Input
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
 
    int N = 7;
 
    insertToBottom(S, N);
 
    return 0;
}

