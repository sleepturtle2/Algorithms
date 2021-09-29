1. K’th Smallest/Largest Element in Unsorted Array | Set 1
-Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

-naive = O(NlogN)
-minHeap = O(N + KlogN) 
-maxHeap = O(K + (N-K)logK) 
-quick sort with lomuto partitioning= The worst case time complexity of this method is O(n2), but it works in O(n) on average
-quick sort with random pivot partitioning = O(N) 
-using median as pivot= O(N) (--> TO DO <--)
-using set stl = O(K + NlogN)


2. K largest(or smallest) elements in an array | added Min Heap method
-Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

= minheap =  O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)

3. Kth smallest element in a row-wise and column-wise sorted 2D array
- Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the given 2D array.

-minheap = O(N+KlogN) where N=row length, space complex = O(N)

4. Find the largest three elements in an array
-Given an array with all distinct elements, find the largest three elements. Expected time complexity is O(n) and extra space is O(1).

-minHeap = O(K+(N-K)logK)
-using three variables = O(N)

5. Find all elements in array which have at-least two greater elements
-Given an array of n distinct elements, the task is to find all elements in array which have at-least two greater elements than themselves.

- using random partition 
- using two variables to store the two highest elements = O(2N)

6. Program to find mean and median of unsorted array
- mean = O(N)
- median - sort array then find median = O(NlogN)
	 - find n/2th element using random partition method = O(N) 

7. Median of stream of integers using stl 
- using max and min heaps - O(NlogN), O(N)

8. Minimum product of k integers in an array of positive Integers
-Given an array of n positive integers. We are required to write a program to print the minimum product of k integers of the given array.

- min heap = O(NlogN)
- random pivot partitioning = O(N)

9. K-th Largest Sum Contiguous Subarray
-Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.
-min heap = O(N^2 logK)
10. K maximum sum combinations from two arrays
-Given two equally sized arrays (A, B) and N (size of both arrays).
A sum combination is made by adding one element from array A and another element of array B. Display the maximum K valid sum combinations from all the possible sum combinations. 
- sorting, minheap, set = O(NlogN) (--->TO DO <---)


11. K maximum contiguous overlapping subarray sums 
-Given an Array of Integers and an Integer value k, find out k sub-arrays(may be overlapping) which have k maximum sums.

- use Bae-Takaota algorithm to solve in O(k*N) time 

12. K maximum non-overlapping subarray sums 
-Given an Array of Integers and an Integer value k, find out k non-overlapping sub-arrays which have k maximum sums.

-use kadanes algo k times = O(k*N)

13. k smallest elements in same order using O(1) extra space
- use any stable sorting algo for last n-k elem = O(summation(n)-summation(n-k)) = O(N^2) worst case when k=n

14. Find k pairs with smallest sums in two arrays
- Given two integer arrays arr1[] and arr2[] sorted in ascending order and an integer k. Find k pairs with smallest sums such that one element of a pair belongs to arr1[] and other element belongs to arr2[]


15. k-th smallest absolute difference of two elements in an array
- We are given an array of size n containing positive integers. The absolute difference between values at indices i and j is |a[i] – a[j]|. There are n*(n-1)/2 such pairs and we are asked to print the kth (1 <= k <= n*(n-1)/2) smallest absolute difference among all these pairs.

-(--->TO DO <---)

16. Find k numbers with most occurrences in the given array
- Given an array of n numbers and a positive integer k. The problem is to find k numbers with most occurrences, i.e., the top k numbers having the maximum frequency. If two numbers have the same frequency then the larger number should be given preference. The numbers should be displayed in decreasing order of their frequencies. It is assumed that the array consists of k numbers with most occurrences.
- max heap and unordered set = O(KlogD + N). where D is #distinct elem

17. Find the smallest missing number 
- Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array. 
- O(logN)

18. Maximum sum such that no two elements are adjacent
- Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.

- using including and excluding sum (DP concept) =O(N)

19. Maximum difference between two elements such that larger element appears after the smaller number
- Given an array arr[] of integers, find out the maximum difference between any two elements such that larger element appears after the smaller number. 
- O(N)

20. Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
- Brute force method = O(N^2)
-using max array = O(N+NlogN) 
- using max and min array O(N) // 3 traversals

21. Sliding Window Maximum (Maximum of all subarrays of size k)
(---> TO DO <----)

22. Find the maximum element in an array which is first increasing and then decreasing
-Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.
(-->sum from the practice section is TODO<--)

23. Count smaller elements on right side
-Write a function to count number of smaller elements on right of each element in an array. Given an unsorted array arr[] of distinct integers, construct another array countSmaller[] such that countSmaller[i] contains count of smaller elements on right side of each element arr[i] in array.
- set =O(N2) , although average case is better than naive
- using avl tree / red black tree- (-->TODO<--)

