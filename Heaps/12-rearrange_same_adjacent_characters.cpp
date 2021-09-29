/*
Rearrange characters in a string such that no two adjacent are same

Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.
Examples: 
 

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible

The idea is to put the highest frequency character first (a greedy approach). We use a priority queue (Or Binary Max Heap) and put all characters and ordered by their frequencies (highest frequency character at root). We one by one take the highest frequency character from the heap and add it to result. After we add, we decrease the frequency of the character and we temporarily move this character out of priority queue so that it is not picked next time.
We have to follow the step to solve this problem, they are: 
1. Build a Priority_queue or max_heap, pq that stores characters and their frequencies. 
…… Priority_queue or max_heap is built on the bases of the frequency of character. 
2. Create a temporary Key that will be used as the previously visited element (the previous element in the resultant string. Initialize it { char = ‘#’ , freq = ‘-1’ } 
3. While pq is not empty. 
….. Pop an element and add it to the result. 
….. Decrease frequency of the popped element by ‘1’ 
….. Push the previous element back into the priority_queue if it’s frequency > ‘0’ 
….. Make the current element as the previous element for the next iteration. 
4. If the length of the resultant string and original string is not equal, print “not possible”. Else print result.
Below is the implementation of above idea */
// C++ program to rearrange characters in a string
// so that no two adjacent characters are same.
#include <bits/stdc++.h>
using namespace std;
 
const int MAX_CHAR = 26;
 
struct Key {
    int freq; // store frequency of character
    char ch;
 
    // function for priority_queue to store Key
    // according to freq
    bool operator<(const Key& k) const
    {
        return freq < k.freq;
    }
};
 
// Function to rearrange character of a string
// so that no char repeat twice
void rearrangeString(string str)
{
    int n = str.length();
 
    // Store frequencies of all characters in string
    int count[MAX_CHAR] = { 0 };
    for (int i = 0; i < n; i++)
        count[str[i] - 'a']++;
 
    // Insert all characters with their frequencies
    // into a priority_queue
    priority_queue<Key> pq;
    for (char c = 'a'; c <= 'z'; c++) {
          int val = c - 'a';
        if (count[val]) {
            pq.push(Key{ count[val], c });
        }
    }
 
    // 'str' that will store resultant value
    str = "";
 
    // work as the previous visited element
    // initial previous element be. ( '#' and
    // it's frequency '-1' )
    Key prev{ -1, '#' };
 
    // traverse queue
    while (!pq.empty()) {
        // pop top element from queue and add it
        // to string.
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;
 
        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.freq > 0)
            pq.push(prev);
 
        // make current character as the previous 'char'
        // decrease frequency by 'one'
        (k.freq)--;
        prev = k;
    }
 
    // If length of the resultant string and original
    // string is not same then string is not valid
    if (n != str.length())
        cout << " Not valid String " << endl;
 
    else // valid string
        cout << str << endl;
}
 
// Driver program to test above function
int main()
{
    string str = "bbbaa";
    rearrangeString(str);
    return 0;
}