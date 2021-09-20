//other names: 

//1. weighted interval scheduling problem 

//2. weighted job sequencing problem 

//3. weighted activity selection problem 

//here greedy does not work. only dp works 

/*
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated (>= 0)
Find the maximum profit subset of jobs such that no two jobs in the subset overlap. 

Example: 

Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
       int start, finish, profit; 
}; 

int findLastNonConflictingJob(vector<Job> const &jobs, int n)
{
       for(int i=n-1; i>=0; i--)
       if(jobs[i].finish <= jobs[n].start)
              return i; 
       return -1; 
}

// A recursive function to find the maximum profit subset of non-overlapping
// jobs, which are sorted according to finish time
int findMaxProfit(vector<Job>&jobs, int n)
{
       //base case 
       if(n<0) return 0; 

       //if only 1 item is remaining 
       if(n==0) return jobs[0].profit; 

       //find index of last non conflicting job with the current job 
       int index = findLastNonConflictingJob(jobs, n); 

       //include the current job and recur for non-conflicting jobs [0,index]
       int incl = jobs[n].profit + findMaxProfit(jobs, index); 

       //exclude the current job and recur for remaining items [0,n-1]
       int excl = findMaxProfit(jobs, n-1); 

       //return the max profit by including and excluding the current job 
       return max(incl , excl); 
}

//wrapper over findMaxProfit function 
int findMaxProfit(vector<Job> jobs)
{      
       //sort based on increasing order of finish times
       sort(jobs.begin(), jobs.end(), [](Job &x, Job &y){
              return x.finish < y.finish; 
       }); 
       return findMaxProfit(jobs, jobs.size() - 1); 
}

int main(){
       vector<Job> jobs {
        { 0, 6, 60 },
        { 1, 4, 30 },
        { 3, 5, 10 },
        { 5, 7, 30 },
        { 5, 9, 50 },
        { 7, 8, 10 }
    };
 
    cout << "The maximum profit is " << findMaxProfit(jobs)<<endl;
 
    return 0;
}