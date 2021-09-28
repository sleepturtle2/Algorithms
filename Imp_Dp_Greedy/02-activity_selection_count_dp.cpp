//variation of the LIS problem 

#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std; 

struct Pair{
    int start; 
    int finish; 
}; 

bool comparison(Pair x, Pair y)
{
    return x.start < y.start; 
}

//returns the max count of non-conflicting jobs that can be performed by a single person
int findNonConflictingJobsLength(vector<Pair> jobs)
{
    //sort the jobs according to the increasing order of their start time
    sort(jobs.begin(), jobs.end(), comparison);

    int Max = INT_MIN; 

    //L[i] stores the max count of non-conflicting jobs ending at ith job
    vector<int>L(jobs.size()); 

    for(int i=0; i<jobs.size(); i++)
    {
        //consider each j less than i
        for(int j=0; j<i; j++)
        {
            //L[i] = max(L[j]), where jobs[j].finish < jobs[i].start
            if(jobs[j].finish < jobs[i].start && L[i] < L[j])
            L[i] = L[j]; 
        }

        //increment L[i] since it ends at ith job 
        L[i]++;
        Max = max(Max, L[i]); 
    } 

    return Max; 
}

int main()
{
    // Each pair stores the start and the finish time of a job
    vector<Pair> jobs =
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
 
    cout << "The maximum number of non-conflicting jobs is "
         << findNonConflictingJobsLength(jobs);
 
    return 0;
}