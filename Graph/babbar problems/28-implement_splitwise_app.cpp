//https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
#include <bits/stdc++.h>
#include "../graph headers/weighted_directed.h"
using namespace std;

int getMin(vector<int> &amount)
{
  int minIndex = 0;
  for (int i = 1; i < amount.size(); i++)
    if (amount[i] < amount[minIndex])
      minIndex = i;

  return minIndex;
}

int getMax(vector<int> &amount)
{
  int maxIndex = 0;
  for (int i = 1; i < amount.size(); i++)
    if (amount[i] > amount[maxIndex])
      maxIndex = i;

  return maxIndex;
}

//amount[p] indicates the net amount to be credited/debited to/from person p
//if amount[p] is +ve, person will give amount [p]
//if -ve, person will give -amount [p]
void minCashFlow_Recursive(vector<int> &amount)
{
  //find indices of minimum and maximum values in amount[]
  //amount[maxCredit] indicates the maximum amount to be given to any person
  //amount[maxDebit] indicates the maximum amount to be taken from any person
  //if there is a positive value in amount, there must also be a negative value

  int maxCredit = getMax(amount), maxDebit = getMin(amount);

  //if both amounts are 0, all accounts are settled
  if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
    return;

  //find minimum of two amounts
  int minOfTwo = min(-amount[maxDebit], amount[maxCredit]);
  amount[maxCredit] -= minOfTwo;
  amount[maxDebit] += minOfTwo;

  cout << "Person " << maxDebit << " pays " << minOfTwo << " to Person " << maxCredit << endl;

  //recur for the amount array. note that it is guaranteed that recursion will terminate as either amount[maxCredit] or amount[maxDebit] becomes 0
  minCashFlow_Recursive(amount);
}

void minCashFlow(vector<vector<int>> &graph)
{
  int V = graph.size();
  vector<int> amount(V);

  //amount[i] = credits of p - debts of p
  for (int person = 0; person < V; person++)
  {
    for (int others = 0; others < V; others++)
    {
      amount[person] += graph[others][person] - graph[person][others];
    }
  }

  minCashFlow_Recursive(amount);
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> graph = {
      {0, 1000, 2000},
      {0, 0, 5000},
      {0, 0, 0},
  };
  minCashFlow(graph);
}
