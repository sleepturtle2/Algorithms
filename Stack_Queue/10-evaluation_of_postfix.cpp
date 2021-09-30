/*

The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix. We have discussed infix to postfix conversion. In this post, evaluation of postfix expressions is discussed.

Following is algorithm for evaluation postfix expressions. 
1) Create a stack to store operands (or values). 
2) Scan the given expression and do the following for every scanned element. 
…..a) If the element is a number, push it into the stack 
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack 
3) When the expression is ended, the number in the stack is the final answer 

Example: 
Let the given expression be “2 3 1 * + 9 -“. We scan all elements one by one. 
1) Scan ‘2’, it’s a number, so push it to stack. Stack contains ‘2’ 
2) Scan ‘3’, again a number, push it to stack, stack now contains ‘2 3’ (from bottom to top) 
3) Scan ‘1’, again a number, push it to stack, stack now contains ‘2 3 1’ 
4) Scan ‘*’, it’s an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result ‘3’ to stack. Stack now becomes ‘2 3’. 
5) Scan ‘+’, it’s an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result ‘5’ to stack. Stack now becomes ‘5’. 
6) Scan ‘9’, it’s a number, we push it to the stack. Stack now becomes ‘5 9’. 
7) Scan ‘-‘, it’s an operator, pop two operands from stack, apply the – operator on operands, we get 5 – 9 which results in -4. We push the result ‘-4’ to stack. Stack now becomes ‘-4’. 
8) There are no more elements to scan, we return the top element from stack (which is the only element left in stack).

*/

// C++ program to evaluate value of a postfix
// expression having multiple digit operands
#include <bits/stdc++.h>
using namespace std;
 
// Stack type
class Stack
{
    public:
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
Stack* createStack( unsigned capacity )
{
    Stack* stack = new Stack();
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];
 
    if (!stack->array) return NULL;
 
    return stack;
}
 
int isEmpty(Stack* stack)
{
    return stack->top == -1 ;
}
 
int peek(Stack* stack)
{
    return stack->array[stack->top];
}
 
int pop(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(Stack* stack,int op)
{
    stack->array[++stack->top] = op;
}
 
 
// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    Stack* stack = createStack(strlen(exp));
    int i;
 
    // See if stack was created successfully
    if (!stack) return -1;
 
    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        //if the character is blank space then continue
        if(exp[i] == ' ')continue;
         
        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.
        else if (isdigit(exp[i]))
        {
            int num=0;
             
            //extract full number
            while(isdigit(exp[i]))
            {
            num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
             
            //push the element in the stack
            push(stack,num);
        }
         
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
             
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
             
            }
        }
    }
    return pop(stack);
}
 
// Driver code
int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}
 