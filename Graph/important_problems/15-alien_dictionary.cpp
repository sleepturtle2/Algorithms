//https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
  int V;
  //pointer to array of int lists
  list<int> *adj;

  void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack)
  {
    visited[v] = true;
    for (int i : adj[v])
      if (!visited[i])
        topologicalSortUtil(i, visited, Stack);

    Stack.push(v);
  }

public:
  Graph(int V)
  {
    this->V = V;
    adj = new list<int>[V];
  }
  void print()
  {
    cout << "Graph:" << endl;
    for (int i = 0; i < V; i++)
    {
      list<int>::iterator it;
      for (it = adj[i].begin(); it != adj[i].end(); it++)
        cout << (char)(*it + 'a') << " ";
      cout << "\n";
    }
    cout << "----\n";
  }
  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
  }

  void topologicalSort()
  {
    stack<int> Stack;
    vector<bool> visited(V);

    for (int i = 0; i < V; i++)
      if (!visited[i])
        topologicalSortUtil(i, visited, Stack);

    //print contents of stack
    while (!Stack.empty())
    {
      cout << (char)('a' + Stack.top()) << " ";
      Stack.pop();
    }
    cout << "\n";
  }
};

void printOrder(vector<string> &words, int n, int alpha)
{
  //create a graph with 'alpha' edges
  Graph g(alpha);

  //process adjacent pairs of words and create a graph
  for (int i = 0; i < n - 1; i++)
  {

    //take two current words and find the first mismatch character
    string word1 = words[i];
    string word2 = words[i + 1];

    for (int j = 0; j < word1.length(); j++)
    {
      //if mismatch, add edge from character of word1 to character of word2
      if (word1[j] != word2[j])
      {
        //cout << word1[j] << " " << word2[j] << endl;
        g.addEdge(word1[j] - 'a', word2[j] - 'a');
        break;
      }
    }
  }
  g.print();
  //print topological sort of above created graph
  g.topologicalSort();
}
int main()
{
  vector<string> words = {"caa", "aaa", "aab"}; //length of words are same
  int sizeOfWords = words[0].length();
  int alphabetSize = words.size();
  printOrder(words, sizeOfWords, alphabetSize);
}
