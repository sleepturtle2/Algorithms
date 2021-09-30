/*
Another efficient solution can be to find out the first petrol pump where the 
amount of petrol is greater than or equal to the distance to be covered to 
reach the next petrol pump. Now we mark that petrol pump as start and now we 
check whether we can finish the journey towards the end point. If in the 
middle, at any petrol pump, the amount of petrol is less than the distance to 
be covered to reach the next petrol pump, then we can say we cannot complete 
the circular tour from start. We again try to find out the next point from 
where we can start our journey i.e. the next petrol pump where the amount of 
petrol is greater than or equal to the distance to be covered and we mark it 
as start. We need not look at any petrol pump in between the initial petrol 
pump marked as start and the new start as we know that we cannot complete the 
journey if we start from any middle petrol pump because eventually we will 
arrive at a point where amount of petrol is less than the distance. Now we 
repeat the process until we reach the last petrol pump and update our start as 
and when required. After we reach our last petrol pump, we try to reach our 
first petrol pump from the last and let’s say we have a remaining amount of 
petrol as curr_petrol. Now we again start traveling from the first petrol pump 
and take the advantage of our curr_petrol and try to reach the start. If we 
can reach the start, then we may conclude that start can be our starting point.
*/

// C++ program to find circular tour for a truck
#include <bits/stdc++.h>
using namespace std;
 
// A petrol pump has petrol and distance to next petrol pump
class petrolPump {
public:
    int petrol;
    int distance;
};
 
// The function returns starting point if there is a
// possible solution, otherwise returns -1
int printTour(petrolPump arr[], int n)
{
    int start;
 
    for (int i = 0; i < n; i++) {
        // Identify the first petrol pump from where we
        // might get a full circular tour
        if (arr[i].petrol >= arr[i].distance) {
            start = i;
            break;
        }
    }
 
    // To store the excess petrol
    int curr_petrol = 0;
 
    int i;
 
    for (i = start; i < n;) {
 
        curr_petrol += (arr[i].petrol - arr[i].distance);
 
        // If at any point remaining petrol is less than 0,
        // it means that we cannot start our journey from
        // current start
        if (curr_petrol < 0) {
 
            // We move to the next petrol pump
            i++;
 
            // We try to identify the next petrol pump from
            // where we might get a full circular tour
            for (; i < n; i++) {
                if (arr[i].petrol >= arr[i].distance) {
 
                    start = i;
 
                    // Reset rem_petrol
                    curr_petrol = 0;
 
                    break;
                }
            }
        }
 
        else {
            // Move to the next petrolpump if curr_petrol is
            // >= 0
            i++;
        }
    }
 
    // If remaining petrol is less than 0 while we reach the
    // first petrol pump, it means no circular tour is
    // possible
    if (curr_petrol < 0) {
        return -1;
    }
 
    for (int j = 0; j < start; j++) {
 
        curr_petrol += (arr[j].petrol - arr[j].distance);
 
        // If remaining petrol is less than 0 at any point
        // before we reach initial start, it means no
        // circular tour is possible
        if (curr_petrol < 0) {
            return -1;
        }
    }
 
    // If we have successfully reached intial_start, it
    // means can get a circular tour from final_start, hence
    // return it
    return start;
}
// Driver code
int main()
{
    petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);
 
    (start == -1) ? cout << "No solution"
                  : cout << "Start = " << start;
 
    return 0;
}
 