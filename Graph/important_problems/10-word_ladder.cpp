//https://www.geeksforgeeks.org/word-ladder-length-of-shortest-chain-to-reach-a-target-word/

#include <bits/stdc++.h>
using namespace std;

int shortestChainLen(string start, string target, set<string> &D)
{

  if (start == target)
    return 0;

  //if target is not present in the dictionary
  if (D.find(target) == D.end())
    return 0;

  //to store current chain length and the length of the words
  int level = 0, wordLength = start.size();

  //push the starting word into the queue
  queue<string> queue;
  queue.push(start);

  while (!queue.empty())
  {
    ++level;

    //current size of the queue
    int sizeQ = queue.size();

    //since the queue is constantly getting updated while being traversed, so only the elements which were already present in the queue before the start of this loop will be traversed for now
    for (int i = 0; i < sizeQ; i++)
    {

      //remove first word from the queue
      string word = queue.front();
      queue.pop();

      //for every character of the word
      for (int pos = 0; pos < wordLength; pos++)
      {

        //retain the original character at the original position
        char orig_char = word[pos];

        //replace the current character with every possible lowercase alphabet
        for (char c = 'a'; c <= 'z'; c++)
        {
          word[pos] = c;

          //if new word is the target word
          if (word == target)
            return level + 1;

          //remove the word from the set if it is found in it
          if (D.find(word) == D.end())
            continue;
          D.erase(word);

          //push newly generated word which will be part of the chain
          queue.push(word);
        }

        //restore the original character at the current position
        word[pos] = orig_char;
      }
    }
  }
  return 0;
}
int main()
{
  set<string> D; //dictionary
  D.insert("poon");
  D.insert("plee");
  D.insert("same");
  D.insert("poie");
  D.insert("plie");
  D.insert("poin");
  D.insert("plea");
  string start = "toon";
  string target = "plea";

  cout << "Length of the shortest chain:" << shortestChainLen(start, target, D) << endl;

  return 0;
}
