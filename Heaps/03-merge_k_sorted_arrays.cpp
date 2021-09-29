/*
Merge k sorted arrays | Set 2 (Different Sized Arrays)
https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/

A simple solution is to create an output array and and one by one copy all arrays to it. Finally, sort the output array using. This approach takes O(N Logn N) time where N is count of all elements.
An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k).
1. Create an output array. 
2. Create a min heap of size k and insert 1st element in all the arrays into the heap 
3. Repeat following steps while priority queue is not empty. 
…..a) Remove minimum element from heap (minimum is always at root) and store it in output array. 
…..b) Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.
 
 */


#include<bits/stdc++.h>
using namespace std; 


// A pair of pairs, first element is going to
// store value, second element index of array
// and third element index in the array.
typedef pair<int,pair<int,int>> ppi; 

vector<int> mergeKArrays(vector<vector<int>>&arr)
{
    vector<int>output; 

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi>>pq; 

    for(int i=0; i<arr.size(); i++)
    pq.push({arr[i][0], {i,0}}); 

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while(!pq.empty())
    {
        ppi curr = pq.top(); 
        pq.pop(); 

        //i = Array number 
        //j = index in the array number 
        int i = curr.second.first; 
        int j = curr.second.second; 
        int val = curr.first; 

        output.push_back(val); 

        //next element is pushed from current 
        if(j+1 < arr[i].size())
            pq.push({arr[i][j+1],{i, j+1}}); 
    }
    return output; 
}

// Driver program to test above functions
int main()
{
    // Change n at the top to change number
    // of elements in an array
    vector<vector<int> > arr{ { 2, 6, 12 },
                              { 1, 9 },
                              { 23, 34, 90, 2000 } };
 
    vector<int> output = mergeKArrays(arr);
 
    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";
 
    return 0;
}