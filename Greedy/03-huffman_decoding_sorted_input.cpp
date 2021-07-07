/*Time complexity of the algorithm discussed in above post is O(nLogn). If we know that the given array is sorted (by non-decreasing order of frequency), we can generate Huffman codes in O(n) time. Following is a O(n) algorithm for sorted input.
1. Create two empty queues.
2. Create a leaf node for each unique character and Enqueue it to the first queue in non-decreasing order of frequency. Initially second queue is empty.
3. Dequeue two nodes with the minimum frequency by examining the front of both queues. Repeat following steps two times
        1. If second queue is empty, dequeue from first queue.
        2. If first queue is empty, dequeue from second queue.
        3. Else, compare the front of two queues and dequeue the minimum.
4. Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the first Dequeued node as its left child and the second Dequeued node as right child. Enqueue this node to second queue.
5. Repeat steps#3 and #4 while there is more than one node in the queues. The remaining node is the root node and the tree is complete. */

// C++ Program for Efficient Huffman Coding for Sorted input
#include <bits/stdc++.h>
using namespace std;

// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100

// A node of huffman tree
class QueueNode
{
public:
  char data;
  unsigned freq;
  QueueNode *left, *right;
};

// Structure for Queue: collection
// of Huffman Tree nodes (or QueueNodes)
class Queue
{
public:
  int front, rear;
  int capacity;
  QueueNode **array;
};

// A utility function to create a new Queuenode
QueueNode *newNode(char data, unsigned freq)
{
  QueueNode *temp = new QueueNode[(sizeof(QueueNode))];
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

// A utility function to create a Queue of given capacity
Queue *createQueue(int capacity)
{
  Queue *queue = new Queue[(sizeof(Queue))];
  queue->front = queue->rear = -1;
  queue->capacity = capacity;
  queue->array = new QueueNode *[(queue->capacity * sizeof(QueueNode *))];
  return queue;
}

// A utility function to check if size of given queue is 1
int isSizeOne(Queue *queue)
{
  return queue->front == queue->rear && queue->front != -1;
}

// A utility function to check if given queue is empty
int isEmpty(Queue *queue) { return queue->front == -1; }

// A utility function to check if given queue is full
int isFull(Queue *queue)
{
  return queue->rear == queue->capacity - 1;
}

// A utility function to add an item to queue
void enQueue(Queue *queue, QueueNode *item)
{
  if (isFull(queue))
    return;
  queue->array[++queue->rear] = item;
  if (queue->front == -1)
    ++queue->front;
}

// A utility function to remove an item from queue
QueueNode *deQueue(Queue *queue)
{
  if (isEmpty(queue))
    return NULL;
  QueueNode *temp = queue->array[queue->front];
  if (queue->front == queue
                          ->rear) // If there is only one item in queue
    queue->front = queue->rear = -1;
  else
    ++queue->front;
  return temp;
}

// A utility function to get from of queue
QueueNode *getFront(Queue *queue)
{
  if (isEmpty(queue))
    return NULL;
  return queue->array[queue->front];
}

/* A function to get minimum item from two queues */
QueueNode *findMin(Queue *firstQueue, Queue *secondQueue)
{
  // Step 3.a: If first queue is empty, dequeue from
  // second queue
  if (isEmpty(firstQueue))
    return deQueue(secondQueue);

  // Step 3.b: If second queue is empty, dequeue from
  // first queue
  if (isEmpty(secondQueue))
    return deQueue(firstQueue);

  // Step 3.c: Else, compare the front of two queues and
  // dequeue minimum
  if (getFront(firstQueue)->freq < getFront(secondQueue)->freq)
    return deQueue(firstQueue);

  return deQueue(secondQueue);
}

// Utility function to check if this node is leaf
int isLeaf(QueueNode *root)
{
  return !(root->left) && !(root->right);
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    cout << arr[i];
  cout << endl;
}

// The main function that builds Huffman tree
QueueNode *buildHuffmanTree(char data[], int freq[],
                            int size)
{
  QueueNode *left, *right, *top;

  // Step 1: Create two empty queues
  Queue *firstQueue = createQueue(size);
  Queue *secondQueue = createQueue(size);

  // Step 2:Create a leaf node for each unique character
  // and Enqueue it to the first queue in non-decreasing
  // order of frequency. Initially second queue is empty
  for (int i = 0; i < size; ++i)
    enQueue(firstQueue, newNode(data[i], freq[i]));

  // Run while Queues contain more than one node. Finally,
  // first queue will be empty and second queue will
  // contain only one node
  while (
      !(isEmpty(firstQueue) && isSizeOne(secondQueue)))
  {
    // Step 3: Dequeue two nodes with the minimum
    // frequency by examining the front of both queues
    left = findMin(firstQueue, secondQueue);
    right = findMin(firstQueue, secondQueue);

    // Step 4: Create a new internal node with frequency
    // equal to the sum of the two nodes frequencies.
    // Enqueue this node to second queue.
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    enQueue(secondQueue, top);
  }

  return deQueue(secondQueue);
}

// Prints huffman codes from the root of Huffman Tree. It
// uses arr[] to store codes
void printCodes(QueueNode *root, int arr[], int top)
{
  // Assign 0 to left edge and recur
  if (root->left)
  {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  // Assign 1 to right edge and recur
  if (root->right)
  {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  // If this is a leaf node, then it contains one of the
  // input characters, print the character and its code
  // from arr[]
  if (isLeaf(root))
  {
    cout << root->data << ": ";
    printArr(arr, top);
  }
}

// The main function that builds a Huffman Tree and print
// codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
  // Construct Huffman Tree
  QueueNode *root = buildHuffmanTree(data, freq, size);

  // Print Huffman codes using the Huffman tree built
  // above
  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);
}

// Driver code
int main()
{
  char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(arr) / sizeof(arr[0]);
  HuffmanCodes(arr, freq, size);
  return 0;
}
/*
  Output:

f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
Time complexity: O(n)
If the input is not sorted, it need to be sorted first before it can be processed by the above algorithm. Sorting can be done using heap-sort or merge-sort both of which run in Theta(nlogn). So, the overall time complexity becomes O(nlogn) for unsorted input. */
