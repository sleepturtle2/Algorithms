/*
A greedy solution of time complexity O(n2) is already discussed here. Below is the simple Greedy Algorithm.

Sort all jobs in decreasing order of profit.
Initialize the result sequence as first job in sorted jobs.
Do following for remaining n-1 jobs 
If the current job can fit in the current result sequence without missing the deadline, add current job to the result. Else ignore the current job.
The costly operation in the Greedy solution is to assign a free slot for a job. We were traversing each and every slot for a job and assigning the greatest possible time slot(<deadline) which was available.
What does greatest time slot means? 
Suppose that a job J1 has a deadline of time t = 5. We assign the greatest time slot which is free and less than the deadline i.e 4-5 for this job. Now another job J2 with deadline of 5 comes in, so the time slot allotted will be 3-4 since 4-5 has already been allotted to job J1.
Why to assign greatest time slot(free) to a job? 
Now we assign the greatest possible time slot since if we assign a time slot even lesser than the available one than there might be some other job which will miss its deadline. 

Example: 
J1 with deadline d1 = 5, profit 40 
J2 with deadline d2 = 1, profit 20 
Suppose that for job J1 we assigned time slot of 0-1. Now job J2 cannot be performed since we will perform Job J1 during that time slot.
Using Disjoint Set for Job Sequencing 
All time slots are individual sets initially. We first find the maximum deadline of all jobs. Let the max deadline be m. We create m+1 individual sets. If a job is assigned a time slot of t where t >= 0, then the job is scheduled during [t-1, t]. So a set with value X represents the time slot [X-1, X]. 
We need to keep track of the greatest time slot available which can be allotted to a given job having deadline. We use the parent array of Disjoint Set Data structures for this purpose. The root of the tree is always the latest available slot. If for a deadline d, there is no slot available, then root would be 0. Below are detailed steps.
Initialize Disjoint Set: Creates initial disjoint sets.



// m is maximum deadline of a job
parent = new int[m + 1];

// Every node is a parent of itself
for (int i = 0; i ≤ m; i++)
    parent[i] = i;
Find : Finds the latest time slot available. 

// Returns the maximum available time slot
find(s)
{
    // Base case
    if (s == parent[s])
       return s;

    // Recursive call with path compression
    return parent[s] = find(parent[s]);
} 
Union : 

 Merges two sets.  
// Makes u as parent of v.
union(u, v)
{
   // update the greatest available
   // free slot to u
   parent[v] = u;
} 
How come find returns the latest available time slot? 
Initially all time slots are individual slots. So the time slot returned is always maximum. When we assign a time slot ‘t’ to a job, we do union of ‘t’ with ‘t-1’ in a way that ‘t-1’ becomes parent of ‘t’. To do this we call union(t-1, t). This means that all future queries for time slot t would now return the latest time slot available for set represented by t-1.
*/

#include<bits/stdc++.h>
using namespace std; 

struct Job{
    char id; 
    int deadline; 
    int profit;
}; 

struct DisjointSet{
    int *parent; 

    DisjointSet(int n)
    {
        parent = new int[n+1]; 
        for(int i=0; i<=n; i++)
        parent[i] = i; 
    }

    //path compression
    int find(int s)
    {
        if(s == parent[s])
        return s; 

        return parent[s] = find(parent[s]); 
    }

    //makes u as parent of v
    void merge(int u, int v)
    {
        parent[v] = u; 
    }
}; 

//sort in descending order of profit 
bool comparison(Job a, Job b)
{
    return a.profit > b.profit; 
}

//returns the maximum deadline from the set of jobs 
int findMaxDeadline(struct Job arr[], int n)
{
    int ans = INT_MIN; 
    for(int i=0; i<n; i++)
        ans = max(ans, arr[i].deadline); 
    return ans; 
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, comparison); 

    //find the max deadline among all jobs and create a disjoint set data structure with maxDeadline disjoint sets initially 
    int maxDeadline = findMaxDeadline(arr, n);         
    DisjointSet ds(maxDeadline); 

    //traverse through all the jobs 
    for(int i=0; i<n; i++)
    {
        //find max available free slot for this job, corresponding to its deadline
        int availableSlot = ds.find(arr[i].deadline); 

        //if max available slot > 0, free slot avaiable
        if(availableSlot > 0)
        {
            cout<<availableSlot<<" "; 
            // This slot is taken by this job 'i'
            // so we need to update the greatest
            // free slot. Note that, in merge, we
            // make first parameter as parent of
            // second parameter. So future queries
            // for availableSlot will return maximum
            // available slot in set of
            // "availableSlot - 1"
            ds.merge(ds.find(availableSlot - 1), availableSlot); 

            cout<<arr[i].id<<" "; 
        }
    }
}

int main()
{
     Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },
                   { 'c', 2, 27 },  { 'd', 1, 25 },
                   { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following jobs need to be "
         << "executed for maximum profit\n";
    printJobScheduling(arr, n);
    return 0; 
}