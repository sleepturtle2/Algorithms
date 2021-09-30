/*
Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1, e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 2^2 = 9.
Expected Time Complexity: O(k*logn)
Examples: 
 

Input :  str = abccc, K = 1
Output :  6
We remove c to get the value as 12 + 12 + 22

Input :  str = aaab, K = 2
Output :  2

One clear observation is that we need to remove character with highest frequency. One trick is the character ma
A Simple solution is to use sorting technique through all current highest frequency reduce up to k times. For After every reduce again sort frequency array. 
A Better Solution used to Priority Queue which has to the highest element on top. 
 

Initialize empty priority queue.
Count frequency of each character and Store into temp array.
Remove K characters which have highest frequency from queue.
Finally Count Sum of square of each element and return it.

*/