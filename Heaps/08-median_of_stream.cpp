/*
Median of Stream of Running Integers using STL

Given that integers are being read from a data stream. Find the median of all
the elements read so far starting from the first integer till the last integer.

Approach: The idea is to use max heap and min heap to store the elements of 
higher half and lower half. Max heap and min heap can be implemented using 
priority_queue in C++ STL. Below is the step by step algorithm to solve this 
problem.

Algorithm: 
 

Create two heaps. One max heap to maintain elements of lower half and one min 
heap to maintain elements of higher half at any point of time..
Take initial value of median as 0.
For every newly read element, insert it into either max heap or min-heap and calculate the median based on the following conditions: 
If the size of max heap is greater than the size of min-heap and the element 
is less than the previous median then pop the top element from max heap and 
insert into min-heap and insert the new element to max heap else insert the 
new element to min-heap. Calculate the new median as the average of top of 
elements of both max and min heap.

If the size of max heap is less than the size of min-heap and the element is 
greater than the previous median then pop the top element from min-heap and 
insert into the max heap and insert the new element to min heap else insert 
the new element to the max heap. Calculate the new median as the average of 
top of elements of both max and min heap.

If the size of both heaps is the same. Then check if the current is less than 
the previous median or not. If the current element is less than the previous 
median then insert it to the max heap and a new median will be equal to the 
top element of max heap. If the current element is greater than the previous 
median then insert it to min-heap and new median will be equal to the top 
element of min heap.
*/

#include<bits/stdc++.h>
using namespace std; 

void printMedians(double arr[], int n)
{
    priority_queue<double>small; //stores the lower half of elements 
    priority_queue<double, vector<double>, greater<double>>great; //upper half of elements 

    double med = arr[0]; 
    small.push(arr[0]); 

    cout<<med<<" "; 

     // reading elements of stream one by one
    /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */
    
    for(int i=1; i<n; i++)
    {
        double x = arr[i]; 

        //Case 1, max heap has more elements 
        if(small.size() > great.size())
        {
            if(x < med)
            {
                great.push(small.top()); //transfer 1 element 
                small.pop(); 
                small.push(x); 
            }
            else{
                great.push(x);
            }

            med = (small.top() + great.top())/2.0; 
        }

        //Case 2, both heaps are of same size 
        else if(small.size() == great.size())
        {
            if(x < med)
            {
                small.push(x); 
                med = (double) small.top(); 
            }
            else
            {
                great.push(x); 
                med = (double)great.top(); 
            }
        }

        //Case 3, min heap has more elements
        else {
            if(x > med)
            {
                small.push(great.top()); 
                great.pop(); 
                great.push(x); 
            }
            else{
                small.push(x); 
            }

            med = (small.top() + great.top())/2.0; 
        }
        cout<<med<<" "; 
    }
    cout<<endl; 
}

int main()
{
    // stream of integers
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}

/*
Time Complexity: O(n Log n). 
Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).
Auxiliary Space : O(n). 
The Space required to store the elements in Heap is O(n).
*/
