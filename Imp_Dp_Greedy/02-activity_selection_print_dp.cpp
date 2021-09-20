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

void findNonConflictingJobs(vector<Pair> jobs)
{
    sort(jobs.begin(), jobs.end(), comparison); 

    vector<vector<Pair>>L(jobs.size()); 
    int Max = INT_MIN; 
    int Max_size = 0; 
    for(int i=0; i<jobs.size(); i++)
    {
        for(int j=0; j<i; j++)
        if(jobs[j].finish < jobs[i].start && L[i].size() < L[j].size()){
            L[i] = L[j]; 
        }
        L[i].push_back(jobs[i]); 
        if(L[i].size() > Max_size)
        {
            Max_size = L[i].size(); 
            Max = i; 
        }
    }

    for(Pair pair : L[Max])
    cout<<pair.start<<" "<<pair.finish<<endl;     
}

int main()
{
     // Each pair stores the start and the finish time of a job
    vector<Pair> jobs =
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
 
    findNonConflictingJobs(jobs);
 
    return 0;
}