/*
Merge k sorted linked lists 
Given k linked lists each of size n and each list is sorted in non-decreasing order, merge them into a single sorted (non-decreasing order) linked list and print the sorted linked list as output.
Examples: 

Input: k = 3, n =  4
list1 = 1->3->5->7->NULL
list2 = 2->4->6->8->NULL
list3 = 0->9->10->11->NULL

Output: 0->1->2->3->4->5->6->7->8->9->10->11
Merged lists in a sorted order 
where every element is greater 
than the previous element.
*/

#include<bits/stdc++.h>
using namespace std; 
struct Node{
    int data; 
    struct Node* next; 
}; 

struct Node* newNode(int data)
{
    struct Node* new_node = new Node(); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
};

struct compare{
    bool operator()(struct Node* a, struct Node* b){
        return a->data > b->data; 
    }
};

struct Node* mergeKSortedLists(struct Node* arr[], int k)
{
    priority_queue<Node*, vector<Node*>, compare>pq; 

    for(int i=0; i<k; i++)
    if(arr[i]!=NULL)
    pq.push(arr[i]); 

    if(pq.empty())
    return NULL; 

    struct Node* dummy = newNode(0); 
    struct Node* last = dummy; 

    while(!pq.empty())
    {
        struct Node* curr = pq.top(); 
        pq.pop(); 

        last->next = curr; 
        last = last->next; 

        if(curr->next != NULL)
        pq.push(curr->next);
    }
    return dummy->next; 
}

void printList(struct Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" "; 
        head  = head->next; 
    }
    cout<<endl; 
}

int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list
 
    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];
 
    // creating k = 3 sorted lists
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // merge the k sorted lists
    struct Node* head = mergeKSortedLists(arr, k);
 
    // print the merged list
    printList(head);
 
    return 0;
}