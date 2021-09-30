/*
In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem. 

Examples:  

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 0},
           {0, 0, 1, 0} }
Output:id = 2
Explanation: The person with ID 2 does not 
know anyone but everyone knows him

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0} }
Output: No celebrity
Explanation: There is no celebrity.
*/

/*
We measure the complexity in terms of calls made to HaveAcquaintance().

Method 1: This uses Graph to arrive at the particular solution.

Approach: 
Model the solution using graphs. Initialize indegree and outdegree of every vertex as 0. If A knows B, draw a directed edge from A to B, increase indegree of B and outdegree of A by 1. Construct all possible edges of the graph for every possible pair [i, j]. There are NC2 pairs. If a celebrity is present in the party, there will be one sink node in the graph with outdegree of zero and indegree of N-1. 
 

Algorithm: 



Create two arrays indegree and outdegree, to store the indegree and outdegree
Run a nested loop, the outer loop from 0 to n and inner loop from 0 to n.
For every pair i, j check if i knows j then increase the outdegree of i and indegree of j
For every pair i, j check if j knows i then increase the outdegree of j and indegree of i
Run a loop from 0 to n and find the id where the indegree is n-1 and outdegree is 0
Time Complexity: O(n2). 
A nested loop is run traversing the array, SO the time complexity is O(n2)
Space Complexity: O(n). 
Since extra space of size n is required.

Approach: There are some observations based on elimination technique (Refer Polya’s How to Solve It book). 

If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
Repeat above two steps till there is only one person.
Ensure the remained person is a celebrity. (What is the need of this step?)
Algorithm: 

Create a stack and push all the id’s in the stack.
Run a loop while there are more than 1 element in the stack.
Pop top two element from the stack (represent them as A and B)
If A knows B, then A can’t be a celebrity and push B in stack. Else if A doesn’t know B, then B can’t be a celebrity push A in stack.
Assign the remaining element in the stack as the celebrity.
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
*/

// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;
 
// Max # of persons in the party
#define N 8
 
// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
 
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
 
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    // Handle trivial
    // case of size = 2
    stack<int> s;
 
    // Celebrity
    int C;
 
    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);
 
    // Extract top 2
  
 
    // Find a potential celebrity
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }
    // If there are only two people
    // and there is no
    // potential candicate
    if(s.empty())
        return -1;
   
   
    // Potential candidate?
    C = s.top();
    s.pop();
 
    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ( (i != C) &&
                (knows(C, i) ||
                 !knows(i, C)) )
            return -1;
    }
 
    return C;
}
 
// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}

/*
Complexity Analysis: 

Time Complexity: O(n). 
The total number of comparisons 3(N-1), so the time complexity is O(n).
Space Complexity: O(n). 
n extra space is needed to store the stack.
*/
