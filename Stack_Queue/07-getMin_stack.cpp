/*
https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
Question: Design a Data Structure SpecialStack that supports all the stack 
operations like push(), pop(), isEmpty(), isFull() and an additional operation 
getMin() which should return minimum element from the SpecialStack. All these 
operations of SpecialStack must be O(1). To implement SpecialStack, you should 
only use standard Stack data structure and no other data structure like 
arrays, list, .. etc. 
Example: 
 

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 
which is the minimum in the current stack.

In this article, a new approach is discussed that supports minimum with O(1) extra space. We define a variable minEle that stores the current minimum element in the stack. Now the interesting part is, how to handle the case when minimum element is removed. To handle this, we push “2x – minEle” into the stack instead of x so that previous minimum element can be retrieved using current minEle and its value stored in stack. Below are detailed steps and explanation of working.
Push(x) : Inserts x at the top of stack. 
 

If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
Pop() : Removes an element from top of stack. 
 

Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
Important Points: 
 



Stack doesn’t hold actual value of an element if it is minimum so far.
Actual minimum element is always stored in minEle
*/

// C++ program to implement a stack that supports
// getMinimum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
 
// A user defined stack that supports getMin() in
// addition to push() and pop()
struct MyStack
{
    stack<int> s;
    int minEle;
 
    // Prints minimum element of MyStack
    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";
 
        // variable minEle stores the minimum element
        // in the stack.
        else
            cout <<"Minimum Element in the stack is: "
                 << minEle << "\n";
    }
 
    // Prints top element of MyStack
    void peek()
    {
        if (s.empty())
        {
            cout << "Stack is empty ";
            return;
        }
 
        int t = s.top(); // Top element.
 
        cout << "Top Most Element is: ";
 
        // If t < minEle means minEle stores
        // value of t.
        (t < minEle)? cout << minEle: cout << t;
    }
 
    // Remove the top element from MyStack
    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
 
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
 
        // Minimum will change as the minimum element
        // of the stack is being removed.
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }
 
        else
            cout << t << "\n";
    }
 
    // Removes top element from MyStack
    void push(int x)
    {
        // Insert new number into the stack
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            cout <<  "Number Inserted: " << x << "\n";
            return;
        }
 
        // If new number is less than minEle
        if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }
 
        else
           s.push(x);
 
        cout <<  "Number Inserted: " << x << "\n";
    }
};
 
// Driver Code
int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
 
    return 0;
}
