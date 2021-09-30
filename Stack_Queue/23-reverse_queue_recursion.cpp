/*
Given a queue, write a recursive function to reverse it. 
Standard operations allowed : 
enqueue(x) : Add an item x to rear of queue. 
dequeue() : Remove an item from front of queue. 
empty() : Checks if a queue is empty or not.
Examples : 
 

Input : Q = [5, 24, 9, 6, 8, 4, 1, 8, 3, 6]
Output : Q = [6, 3, 8, 1, 4, 8, 6, 9, 24, 5]

Explanation : Output queue is the reverse of the input queue.

Input : Q = [8, 7, 2, 5, 1]
Output : Q = [1, 5, 2, 7, 8]
Recursive Algorithm : 
 

The pop element from the queue if the queue has elements otherwise return empty queue.
Call reverseQueue function for the remaining queue.
Push the popped element in the resultant reversed queue.


queue reverseFunction(queue)
{
    if (queue is empty)
       return queue;
    else {
       data = queue.front()
       queue.pop()
       queue = reverseFunction(queue);
       q.push(data);
       return queue;
    }
}
*/

// C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;
 
// Utility function to print the queue
void printQueue(queue<long long int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
 
// Recursive function to reverse the queue
void reverseQueue(queue<long long int>& q)
{
    // Base case
    if (q.empty())
        return;
 
    // Dequeue current item (from front) 
    long long int data = q.front();
    q.pop();
 
    // Reverse remaining queue 
    reverseQueue(q);
 
    // Enqueue current item (to rear) 
    q.push(data);
}
 
// Driver code
int main()
{
    queue<long long int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    reverseQueue(Queue);
    printQueue(Queue);
}