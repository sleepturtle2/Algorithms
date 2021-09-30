/*
Given a binary matrix of N x M, containing at least a value 1. The task is to find the distance of nearest 1 in the matrix for each cell. The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

Examples: 

Input : N = 3, M = 4
        mat[][] = { 0, 0, 0, 1,
                    0, 0, 1, 1,
                    0, 1, 1, 0 }
Output : 3 2 1 0
         2 1 0 0
         1 0 0 1
Explanation:
For cell at (0, 0), nearest 1 is at (0, 3),
so distance = (0 - 0) + (3 - 0) = 3.
Similarly, all the distance can be calculated.


This method uses the BFS or breadth-first search technique to arrive at the solution.

Approach: The idea is to use multisource Breadth-First Search. Consider each 
cell as a node and each boundary between any two adjacent cells be an edge. 
Number each cell from 1 to N*M. Now, push all the node whose corresponding 
cell value is 1 in the matrix in the queue. Apply BFS using this queue to find 
the minimum distance of the adjacent node.
Algorithm: 
Create a graph with values assigned from 1 to M*N to all vertices. The purpose 
is to store position and adjacent information.
Create an empty queue.
Traverse all matrix elements and insert positions of all 1s in queue.
Now do a BFS traversal of graph using above created queue.
Run a loop till the size of the queue is greater than 0 then extract the front 
node of the queue and remove it and insert all its adjacent and unmarked 
elements. Update the minimum distance as distance of current node +1 and 
insert the element in the q
*/

// C++ program to find distance of nearest
// cell having 1 in a binary matrix.
#include<bits/stdc++.h>
#define MAX 500
#define N 3
#define M 4
using namespace std;
 
// Making a class of graph with bfs function.
class graph
{
private:
    vector<int> g[MAX];
    int n,m;
 
public:
    graph(int a, int b)
    {
        n = a;
        m = b;
    }
 
    // Function to create graph with N*M nodes
    // considering each cell as a node and each
    // boundary as an edge.
    void createGraph()
    {
        int k = 1;  // A number to be assigned to a cell
 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // If last row, then add edge on right side.
                if (i == n)
                {
                    // If not bottom right cell.
                    if (j != m)
                    {
                        g[k].push_back(k+1);
                        g[k+1].push_back(k);
                    }
                }
 
                // If last column, then add edge toward down.
                else if (j == m)
                {
                    g[k].push_back(k+m);
                    g[k+m].push_back(k);
                }
 
                // Else makes an edge in all four directions.
                else
                {
                    g[k].push_back(k+1);
                    g[k+1].push_back(k);
                    g[k].push_back(k+m);
                    g[k+m].push_back(k);
                }
 
                k++;
            }
        }
    }
 
    // BFS function to find minimum distance
    void bfs(bool visit[], int dist[], queue<int> q)
    {
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
 
            for (int i = 0; i < g[temp].size(); i++)
            {
                if (visit[g[temp][i]] != 1)
                {
                    dist[g[temp][i]] =
                    min(dist[g[temp][i]], dist[temp]+1);
 
                    q.push(g[temp][i]);
                    visit[g[temp][i]] = 1;
                }
            }
        }
    }
 
    // Printing the solution.
    void print(int dist[])
    {
        for (int i = 1, c = 1; i <= n*m; i++, c++)
        {
            cout << dist[i] << " ";
 
            if (c%m == 0)
                cout << endl;
        }
    }
};
 
// Find minimum distance
void findMinDistance(bool mat[N][M])
{
    // Creating a graph with nodes values assigned
    // from 1 to N x M and matrix adjacent.
    graph g1(N, M);
    g1.createGraph();
 
    // To store minimum distance
    int dist[MAX];
 
    // To mark each node as visited or not in BFS
    bool visit[MAX] = { 0 };
 
    // Initialising the value of distance and visit.
    for (int i = 1; i <= M*N; i++)
    {
        dist[i] = INT_MAX;
        visit[i] = 0;
    }
 
    // Inserting nodes whose value in matrix
    // is 1 in the queue.
    int k = 1;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == 1)
            {
                dist[k] = 0;
                visit[k] = 1;
                q.push(k);
            }
            k++;
        }
    }
 
    // Calling for Bfs with given Queue.
    g1.bfs(visit, dist, q);
 
    // Printing the solution.
    g1.print(dist);
}
 
// Driven Program
int main()
{
    bool mat[N][M] =
    {
        0, 0, 0, 1,
        0, 0, 1, 1,
        0, 1, 1, 0
    };
 
    findMinDistance(mat);
 
    return 0;
}

/*
Time Complexity: O(N*M). 
In BFS traversal every element is traversed only once so time Complexity is O(M*N).
Space Complexity: O(M*N). 
To store every element in the matrix O(M*N) space is required.
*/
