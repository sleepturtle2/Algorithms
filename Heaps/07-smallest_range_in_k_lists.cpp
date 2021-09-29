/*
Find smallest range containing elements from k lists
Difficulty Level : Hard
Last Updated : 12 Jun, 2021
Given k sorted lists of integers of size n each, find the smallest range that includes at least element from each of the k lists. If more than one smallest ranges are found, print any one of them.

Example: 

Input: K = 3
arr1[] : [4, 7, 9, 12, 15]
arr2[] : [0, 8, 10, 14, 20]
arr3[] : [6, 12, 16, 30, 50]
Output:
The smallest range is [6 8]

Explanation: Smallest range is formed by 
number 7 from the first list, 8 from second
list and 6 from the third list.

The approach remains the same but the time complexity can be reduced by using min-heap or priority queue. Min heap can be used to find the maximum and minimum value in logarithmic time or log k time instead of linear time. Rest of the approach remains the same. 

Algorithm: 
create an Min heap to store k elements, one from each array and a variable 
minrange initialized to a maximum value and also keep a variable max to store the maximum integer.

Initially put the first element of each element from each list and store the 
maximum value in max.
Repeat the following steps until atleast one list exhausts : 
To find the minimum value or min, use the top or root of the Min heap which is 
the minimum element.
Now update the minrange if current (max-min) is less than minrange.
remove the top or root element from priority queue and insert the next element 
from the list which contains the min element and update the max with the new 
element inserted.
*/

#include <bits/stdc++.h>
using namespace std;
 
#define N 5
typedef pair<int,pair<int,int>> ppi;

void findSmallestRange(int arr[][N], int k)
{
    int range = INT_MAX; 
    int min = INT_MAX, max = INT_MIN; 
    int start, end; 

    priority_queue<ppi, vector<ppi>, greater<ppi>>pq; //el, index of array, index in array 
    //there are k arrays 
    for(int i=0; i<k; i++)
    {
        //store the first elements 
        pq.push({arr[i][0], {i, 0}}); 
        max = max < arr[i][0] ? arr[i][0] : max; 
    }

    while(!pq.empty())
    {
        min = pq.top().first;
        int arr_index = pq.top().second.first; 
        int el_arr_index = pq.top().second.second; 

        cout<<min<<" "<<arr_index<<" "<<el_arr_index<<endl;
        pq.pop(); 

        if(range > max - min)
        {
            range = max - min; 
            start = min; 
            end = max;
        }

        if(el_arr_index + 1 < N)
        {
            pq.push({arr[arr_index][el_arr_index ], {arr_index, el_arr_index}}); 
            max = max < arr[arr_index][el_arr_index] ? arr[arr_index][el_arr_index] : max; 
        }
        else 
        break; 
    }
    cout<<range<<" "<<min<<" "<<max<<endl; 
}

int main()
{
    int arr[][N] = {
        { 4, 7, 9, 12, 15 },
        { 0, 8, 10, 14, 20 },
        { 6, 12, 16, 30, 50 }
    };
    int k = sizeof(arr) / sizeof(arr[0]);
 
    findSmallestRange(arr, k);
 
    return 0;
}