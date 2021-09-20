/*
Given an array of jobs where every job has a deadline and associated profit if
 the job is finished before the deadline. It is also given that every job 
 takes a single unit of time, so the minimum possible deadline for any job is 
 1. How to maximize total profit if only one job can be scheduled at a time.
 Input: Four Jobs with following 
deadlines and profits
JobID  Deadline  Profit
  a      4        20   
  b      1        10
  c      1        40  
  d      1        30
Output: Following is maximum 
profit sequence of jobs
        c, a   


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum 
profit sequence of jobs
        c, a, e
*/


//naive Greedy solution 

/*
A Simple Solution is to generate all subsets of a given set of jobs and check
individual subsets for the feasibility of jobs in that subset. Keep track of
maximum profit among all feasible subsets. The time complexity of this
solution is exponential. 
This is a standard Greedy Algorithm problem. 
*/

#include <bits/stdc++.h>
using namespace std; 

struct Job{
    char id; 
    int deadline; 
    int profit; 
};

bool comparison(Job a, Job b)
{
    return a.profit > b.profit; 
}
//returns the minumum number of platforms required
void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, comparison); 

    int result[n]; //stores sequence of jobs 
    bool slot[n]; //keeps track of free time slots 

    //initialize all slots to be free 
    for(int i=0; i<n; i++)
    slot[i] = false; 

    //iterate through all the given jobs
    for(int i=0; i<n; i++)
    {
        //find a free slot for this job
        //we start from the last possible slot 
        for(int j=min(n, arr[i].deadline)-1; j>=0; j--)
        {
            //free slot found 
            if(slot[j] == false)
            {
                result[j] = i; //add this job to result 
                slot[j] = true; //make slot occupied 
                break; 
            }
        }
    } 

    //print the result 
    for(int i=0; i<n; i++)
    if(slot[i])
    cout<<arr[result[i]].id<<" ";
    cout<<"\n";  
}

int main()
{
    Job arr[] = { {'a',2,100}, {'b',1,19}, {'c',2,27}, {'d',1,25}, {'e',3,15}};
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Maximum profit sequence of jobs\n"; 

    printJobScheduling(arr,n); 
    return 0; 
}