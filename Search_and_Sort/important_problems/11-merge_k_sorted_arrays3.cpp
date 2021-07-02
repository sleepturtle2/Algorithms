/*The idea is to use Min Heap. This MinHeap based solution has the same time complexity which is O(NK log K). But for a different and particular sized array, this solution works much better. The process must start with creating a MinHeap and inserting the first element of all the k arrays. Remove the root element of Minheap and put it in the output array and insert the next element from the array of removed element. To get the result the step must continue until there is no element in the MinHeap left.

MinHeap: A Min-Heap is a complete binary tree in which the value in each internal node is smaller than or equal to the values in the children of that node. Mapping the elements of a heap into an array is trivial: if a node is stored at index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2.

Algorithm:
Create a min Heap and insert the first element of all k arrays.
Run a loop until the size of MinHeap is greater than zero.
Remove the top element of the MinHeap and print the element.
Now insert the next element from the same array in which the removed element belonged.
If the array doesn’t have any more elements, then replace root with infinite.After replacing the root, heapify the tree.
*/

#include <bits/stdc++.h>
using namespace std;

#define n 4

// A min-heap node
struct MinHeapNode
{
  // The element to be stored
  int element;

  // index of the array from which the element is taken
  int i;

  // index of the next element to be picked from the array
  int j;
};

// Prototype of a utility function to swap two min-heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

// A class for Min Heap
class MinHeap
{

  // pointer to array of elements in heap
  MinHeapNode *harr;

  // size of min heap
  int heap_size;

public:
  // Constructor: creates a min heap of given size
  MinHeap(MinHeapNode a[], int size);

  // to heapify a subtree with root at given index
  void MinHeapify(int);

  // to get index of left child of node at index i
  int left(int i) { return (2 * i + 1); }

  // to get index of right child of node at index i
  int right(int i) { return (2 * i + 2); }

  // to get the root
  MinHeapNode getMin() { return harr[0]; }

  // to replace root with new node x and heapify() new root
  void replaceMin(MinHeapNode x)
  {
    harr[0] = x;
    MinHeapify(0);
  }
};

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
int *mergeKArrays(int arr[][n], int k)
{

  // To store output array
  int *output = new int[n * k];

  // Create a min heap with k heap nodes.
  // Every heap node has first element of an array
  MinHeapNode *harr = new MinHeapNode[k];
  for (int i = 0; i < k; i++)
  {

    // Store the first element
    harr[i].element = arr[i][0];

    // index of array
    harr[i].i = i;

    // Index of next element to be stored from the array
    harr[i].j = 1;
  }

  // Create the heap
  MinHeap hp(harr, k);

  // Now one by one get the minimum element from min
  // heap and replace it with next element of its array
  for (int count = 0; count < n * k; count++)
  {
    // Get the minimum element and store it in output
    MinHeapNode root = hp.getMin();
    output[count] = root.element;

    // Find the next elelement that will replace current
    // root of heap. The next element belongs to same
    // array as the current root.
    if (root.j < n)
    {
      root.element = arr[root.i][root.j];
      root.j += 1;
    }
    // If root was the last element of its array
    // INT_MAX is for infinite
    else
      root.element = INT_MAX;

    // Replace root with next element of array
    hp.replaceMin(root);
  }

  return output;
}

// FOLLOWING ARE IMPLEMENTATIONS OF
// STANDARD MIN HEAP METHODS FROM CORMEN BOOK
// Constructor: Builds a heap from a given
// array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
  heap_size = size;
  harr = a; // store address of array
  int i = (heap_size - 1) / 2;
  while (i >= 0)
  {
    MinHeapify(i);
    i--;
  }
}

// A recursive method to heapify a
// subtree with root at given index.
// This method assumes that the subtrees
// are already heapified
void MinHeap::MinHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && harr[l].element < harr[i].element)
    smallest = l;
  if (r < heap_size && harr[r].element < harr[smallest].element)
    smallest = r;
  if (smallest != i)
  {
    swap(&harr[i], &harr[smallest]);
    MinHeapify(smallest);
  }
}

// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
  MinHeapNode temp = *x;
  *x = *y;
  *y = temp;
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
  // Change n at the top to change number of elements
  // in an array
  int arr[][n] = {{2, 6, 12, 34},
                  {1, 9, 20, 1000},
                  {23, 34, 90, 2000}};
  int k = sizeof(arr) / sizeof(arr[0]);

  int *output = mergeKArrays(arr, k);

  cout << "Merged array is " << endl;
  printArray(output, n * k);

  return 0;
}

/*
Complexity Analysis:

Time Complexity :O( n * k * log k), Insertion and deletion in a Min Heap requires log k time. So the Overall time compelxity is O( n * k * log k)
Space Complexity :O(k), If Output is not stored then the only space required is the Min-Heap of k elements. So space Comeplexity is O(k).
*/
