#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

//total number of vertices in the graph
//10 x 10 board
#define N 100

struct Edge
{
  int src, dest;
};

class Graph
{
public:
  vector<int> adjList[N + 1];

  Graph(vector<Edge> const &edges)
  {
    //add edges to the graph
    for (Edge edge : edges)
    {
      int src = edge.src;
      int dest = edge.dest;

      //directed graph
      adjList[src].push_back(dest);
    }
  }
};

//queue Node
struct Node
{
  //stores number associated with graph node
  int ver;
  //stores the minimum distance of a node from the starting vertex
  int min_dist;
};

//perform bfs on graph g starting from a given source vertex
void BFS(Graph const &g, int source)
{
  //create queue for bfs
  queue<Node> queue;

  //to keep track of discovered vertices
  vector<bool> discovered(N + 1);

  //assign the minimum distance of the source vertex as 0 and enqueue it
  Node node = {source, 0};
  queue.push(node);

  while (!queue.empty())
  {
    //dequeue front node
    node = queue.front();
    queue.pop();

    //stop bfs if the last node is reached
    if (node.ver == N)
    {
      cout << node.min_dist << " ";
      break;
    }

    //do every adjacent node of the current node
    for (int u : g.adjList[node.ver])
    {
      if (!discovered[u])
      {

        //mark as discovered and enqueue it
        discovered[u] = true;

        //assign minimum distance of the current node
        //one more than the minimum distance of the parent node
        Node n = {u, node.min_dist + 1};
        queue.push(n);
      }
    }
  }
}

void findSolution(unordered_map<int, int> &ladder, unordered_map<int, int> &snake)
{
  //find all edges involved and store them in a vector
  vector<Edge> edges;

  for (int i = 0; i < N; i++)
  {
    for (int j = 1; j <= 6 && j + i <= N; j++)
    {
      int src = i;

      //update destination if there is any ladder or snake from the current position
      int dest = (ladder[i + j] || snake[i + j]) ? (ladder[i + j] + snake[i + j]) : (i + j);

      //add an edge from src to dest
      Edge e = {src, dest};
      edges.push_back(e);
    }
  }

  //construct directed graph
  Graph g(edges);

  //find the shortest path between 1 and 100 using bfs
  BFS(g, 0);
}

int main()
{
  //snakes and ladders are represented using a map
  unordered_map<int, int> ladder, snake;
  // insert ladders into the map
  ladder[1] = 38;
  ladder[4] = 14;
  ladder[9] = 31;
  ladder[21] = 42;
  ladder[28] = 84;
  ladder[51] = 67;
  ladder[72] = 91;
  ladder[80] = 99;

  // insert snakes into the map
  snake[17] = 7;
  snake[54] = 34;
  snake[62] = 19;
  snake[64] = 60;
  snake[87] = 36;
  snake[93] = 73;
  snake[95] = 75;
  snake[98] = 79;

  findSolution(ladder, snake);

  return 0;
}
