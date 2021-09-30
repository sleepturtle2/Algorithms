/*
Optimal Approach: The idea is to use two pointers, one from start and one from the end. Assume the start person is A, and the end person is B. If A knows B, then A must not be the celebrity. Else, B must not be the celebrity. At the end of the loop, only one index will be left as a celebrity. Go through each person again and check whether this is the celebrity. 
The Two Pointer approach can be used where two pointers can be assigned, one at the start and the other at the end, and the elements can be compared and the search space can be reduced. 
 

Algorithm : 

Create two indices i and j, where i = 0 and j = n-1
Run a loop until i is less than j.
Check if i knows j, then i can’t be a celebrity. so increment i, i.e. i++
Else j cannot be a celebrity, so decrement j, i.e. j–
Assign i as the celebrity candidate
Now at last check that whether the candidate is actually a celebrity by re-running a loop from 0 to n-1  and constantly checking that if the candidate knows a person or if there is a candidate who does not know the candidate, then we should return -1. else at the end of the loop, we can be sure that the candidate is actually a celebrity.
*/

// Java program to find celebrity
// in the given Matrix of people
// Code by Sparsh_cbs
 
import java.io.*;
 
class GFG {
    public static void main(String[] args)
    {
        int[][] M = { { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 } };
 
        int celebIdx = celebrity(M, 4);
 
        if (celebIdx == -1)
            System.out.println("No celebrity found!");
        else {
            System.out.println(
                "0-based celebrity index is : " + celebIdx);
        }
    }
    public static int celebrity(int M[][], int n)
    {
        // This function returns the celebrity
        // index 0-based (if any)
 
        int i = 0, j = n - 1;
        while (i < j) {
            if (M[j][i] == 1) // j knows i
                j--;
            else // i knows j
                i++;
        }
        // i points to our celebrity candidate
        int candidate = i;
 
        // Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one
        for (i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[i][candidate] == 0
                    || M[candidate][i] == 1)
                    return -1;
            }
        }
        // if we reach here this means that the candidate
        // is really a celebrity
        return candidate;
    }
}