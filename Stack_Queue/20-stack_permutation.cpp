/*
The idea to do this is we will try to convert the input queue to output queue using a stack, if we are able to do so then the queue is permutable otherwise not. 
Below is the step by step algorithm to do this: 
 

Continuously pop elements from the input queue and check if it is equal to the top of output queue or not, if it is not equal to the top of output queue then we will push the element to stack. 
 
Once we find an element in input queue such the top of input queue is equal to top of output queue, we will pop a single element from both input and output queues, and compare the top of stack and top of output queue now. If top of both stack and output queue are equal then pop element from both stack and output queue. If not equal, go to step 1. 
 
Repeat above two steps until the input queue becomes empty. At the end if both of the input queue and stack are empty then the input queue is permutable otherwise not. 
*/

// Given two arrays, check if one array is
// stack permutation of other.
#include<bits/stdc++.h>
using namespace std;
 
// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
    // Input queue
    queue<int> input;
    for (int i=0;i<n;i++)
        input.push(ip[i]);
 
    // output queue
    queue<int> output;
    for (int i=0;i<n;i++)
        output.push(op[i]);
 
    // stack to be used for permutation
    stack <int> tempStack;
    while (!input.empty())
    {
        int ele = input.front();
        input.pop();
        if (ele == output.front())
        {
            output.pop();
            while (!tempStack.empty())
            {
                if (tempStack.top() == output.front())
                {
                    tempStack.pop();
                    output.pop();
                }
                else
                    break;
            }
        }
        else
            tempStack.push(ele);
    }
 
    // If after processing, both input queue and
    // stack are empty then the input queue is
    // permutable otherwise not.
    return (input.empty()&&tempStack.empty());
}
 
// Driver program to test above function
int main()
{
    // Input Queue
    int input[] = {1, 2, 3};
 
    // Output Queue
    int output[] = {2, 1, 3};
 
    int n = 3;
 
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}