/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers
Examples:

Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9}
Output : 1 2 4 5
First meeting [1, 2]
Second meeting [3, 4]
Fourth meeting [5, 7]
Fifth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924},
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 }
Output : 6 7 1

Approach:
Idea is to solve the problem using the greedy approach which is the same as Activity Selection Problem.



Sort all pairs(Meetings) in increasing order of second number(Finish time) of each pair.
Select first meeting of sorted pair as the first Meeting in the room and push it into result vector and set a variable time_limet(say) with the second value(Finishing time) of the first selected meeting.
Iterate from the second pair to last pair of the array and if the value of the first element(Starting time of meeting) of the current pair is greater then previously selected pair finish time (time_limit) then select the current pair and update the result vector (push selected meeting number into vector) and variable time_limit.
Print the Order of meeting from vector.
*/
#include <bits/stdc++.h>
using namespace std;

// Structure for storing starting time,
// finishing time and position of meeting.
struct meeting
{
  int start;
  int end;
  int pos;
};

// Comparator function which can compare
// the second element of structure used to
// sort pairs in increasing order of second value.
bool comparator(struct meeting m1, meeting m2)
{
  return (m1.end < m2.end);
}

// Function for finding maximum meeting in one room
void maxMeeting(int s[], int f[], int n)
{
  struct meeting meet[n];
  for (int i = 0; i < n; i++)
  {
    // Starting time of meeting i.
    meet[i].start = s[i];

    // Finishing time of meeting i
    meet[i].end = f[i];

    // Original position/index of meeting
    meet[i].pos = i + 1;
  }

  // Sorting of meeting according to their finish time.
  sort(meet, meet + n, comparator);

  // Vector for storing selected meeting.
  vector<int> m;

  // Initially select first meeting.
  m.push_back(meet[0].pos);

  // time_limit to check whether new
  // meeting can be conducted or not.
  int time_limit = meet[0].end;

  // Check for all meeting whether it
  // can be selected or not.
  for (int i = 1; i < n; i++)
  {
    if (meet[i].start >= time_limit)
    {
      // Push selected meeting to vector
      m.push_back(meet[i].pos);

      // Update time limit.
      time_limit = meet[i].end;
    }
  }

  // Print final selected meetings.
  for (int i = 0; i < m.size(); i++)
  {
    cout << m[i] << " ";
  }
}

// Driver code
int main()
{
  // Starting time
  int s[] = {1, 3, 0, 5, 8, 5};

  // Finish time
  int f[] = {2, 4, 6, 7, 9, 9};

  // Number of meetings.
  int n = sizeof(s) / sizeof(s[0]);

  // Function call
  maxMeeting(s, f, n);

  return 0;
}
/*
Output:

1 2 4 5
Time Complexity: O(N log(N))
*/
