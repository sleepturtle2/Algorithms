/*
Method 1 (By making enQueue operation costly) This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.

enQueue(q, x): 



While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.
Here time complexity will be O(n)

deQueue(q): 

If stack1 is empty then error
Pop an item from stack1 and return it
Here time complexity will be O(1)
*/

// CPP program to implement Queue using
// two stacks with costly enQueue()
#include <bits/stdc++.h>
using namespace std;
 
struct Queue {
    stack<int> s1, s2;
 
    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
 
        // Push item into s1
        s1.push(x);
 
        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }
 
        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};
 
// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
 
    return 0;
}

/*

  Complexity Analysis: 

Time Complexity: 
Push operation: O(N). 
In the worst case we have empty whole of stack 1 into stack 2.
Pop operation: O(1). 
Same as pop operation in stack.
Auxiliary Space: O(N). 
Use of stack for storing values.
Method 2 (By making deQueue operation costly)In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned. 

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)

*/

// CPP program to implement Queue using
// two stacks with costly deQueue()
#include <bits/stdc++.h>
using namespace std;
 
struct Queue {
    stack<int> s1, s2;
 
    // Enqueue an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }
 
        // if s2 is empty, move
        // elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
 
        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};
 
// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
 
    return 0;
}

/*

Complexity Analysis: 

Time Complexity: 
Push operation: O(1). 
Same as pop operation in stack.
Pop operation: O(N). 
In the worst case we have empty whole of stack 1 into stack 2
Auxiliary Space: O(N). 
Use of stack for storing values. 
Queue can also be implemented using one user stack and one Function Call Stack. Below is modified Method 2 where recursion (or Function Call Stack) is used to implement queue using only one user defined stack. 

enQueue(x)
  1) Push x to stack1.

deQueue:
  1) If stack1 is empty then error.
  2) If stack1 has only one element then return it.
  3) Recursively pop everything from the stack1, store the popped item 
    in a variable res,  push the res back to stack1 and return res

*/

// CPP program to implement Queue using
// one stack and recursive call stack.
#include <bits/stdc++.h>
using namespace std;
 
struct Queue {
    stack<int> s;
 
    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }
 
        // pop an item from the stack
        int x = s.top();
        s.pop();
 
        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;
 
        // recursive call
        int item = deQueue();
 
        // push popped item back to the stack
        s.push(x);
 
        // return the result of deQueue() call
        return item;
    }
};
 
// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
 
    return 0;
}

/*
Complexity Analysis: 

Time Complexity: 
Push operation : O(1). 
Same as pop operation in stack.
Pop operation : O(N). 
The difference from above method is that in this method element is returned and all elements are restored back in a single call.
Auxiliary Space: O(N). 
Use of stack for storing values.
*/