
/*
Merge k sorted arrays
https://www.geeksforgeeks.org/merge-k-sorted-arrays/

Efficient Approach The process might begin with merging arrays into groups of two. After the first merge, we have k/2 arrays. Again merge arrays in groups, now we have k/4 arrays. This is similar to merge sort. Divide k arrays into two halves containing an equal number of arrays until there are two arrays in a group. This is followed by merging the arrays in a bottom-up manner. 

Algorithm: 
Create a recursive function which takes k arrays and returns the output array.
In the recursive function, if the value of k is 1 then return the array else if the value of k is 2 then merge the two arrays in linear time and return the array.
If the value of k is greater than 2 then divide the group of k elements into two equal halves and recursively call the function, i.e 0 to k/2 array in one recursive function and k/2 to k array in another recursive function.
Print the output array.

Complexity Analysis:  

Time Complexity: O( n * k * log k). 
There are log k levels as in each level the k arrays are divided in half and at each level the k arrays are traversed. So time Complexity is O( n * k ).
Space Complexity: O( n * k * log k). 
In each level O( n*k ) space is required So Space Complexity is O( n * k * log k).
*/
#include<bits/stdc++.h>
using namespace std; 
#define n 4 

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i=0, j=0, k=0; 

    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        arr3[k++] = arr1[i++]; 
        else 
        arr3[k++] = arr2[j++]; 
    }

    while(i<n1)
    arr3[k++] = arr1[i++]; 

    while(j<n2)
    arr3[k++] = arr2[j++]; 
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    cout<<arr[i]<<" "; 
    cout<<endl; 
}
void mergeKArrays(int arr[][n], int low, int high, int output[])
{
    if(low==high)
    {
        for(int p=0; p<n; p++)
        output[p] = arr[low][p]; return ; 
    }

    if(high-low==1) //2 arrays 
    {
        mergeArrays(arr[low], arr[high], n, n, output); 
        return; 
    }

    int out1[n*((low+high)/2 - low + 1)], out2[n*(high - (high+low)/2)]; 

    mergeKArrays(arr, low, (high+low)/2, out1); 
    mergeKArrays(arr, (low+high)/2+1, high, out2); 

    mergeArrays(out1, out2, n*((high+low)/2 - low + 1), n*(high - (high+low)/2), output ); 
}

int main()
{
    // Change n at the top to change number of elements
    // in an array
    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);
    int output[n*k];
    mergeKArrays(arr,0,2, output);
  
    cout << "Merged array is " << endl;
    printArray(output, n*k);
  
    return 0;
}