/*
https://leetcode.com/problems/surrounded-regions/


Given an m x n matrix board containing 'X' and 'O', capture all regions
that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded
region.


Logical Thought
We aim to find all 'O's such that it is on the border or it is connected to an 'O' on the border. If we regard 'O' mentioned above as a node (or an element), the problem becomes to find the connected components (or disjoint sets) connected to borders. So-called borders should also be represented as an element, so elements connected to it can be merged with it into a set. That's the usage of dummyBorder.
Pseudo-code

initialize dummyRepresentative

for O in board
	if O is on border
		union(dummyBorder, O)
	else
		for neighbour of O
			if (neighbour is 'O') 
				union(neighbour, O)
                
for each cell
	if cell is 'O' && (find(cel) != find(dummyBorder))
		flip

*/

#include<bits/stdc++.h>
using namespace std; 

class DisjointSets{
    vector<int>parent; 

     public: 
    DisjointSets(vector<vector<char>>&board)
    {
        int rows =board.size(); 
        int cols = board[0].size(); 

        int parentLength = rows*cols + 1; 
        parent.resize(parentLength); 

        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x)
    {
        if(x==parent[x])
        return x; 
        else
        return parent[x] = find(parent[x]); 
    }

    void Union(int x, int y)
    {
        int rootX = find(x); 
        int rootY = find(y); 
        if(rootX != rootY) 
            parent[rootY] = rootX; // or parent[rootX] = rootY
    }
}; 


vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}}; 

void solve(vector<vector<char>>&board)
{
    if(board.size() == 0)
    return; 

    DisjointSets *disjointSets = new DisjointSets(board);
    int rows = board.size(); 
    int cols = board[0].size(); 
    int dummyBorder = rows*cols; 

    for(int x=0; x<rows; x++)
    {
        for(int y=0; y<cols; y++)
        {
            if(board[x][y] == 'O')
            {
                int borderO = x*cols + y; 
                if(x==0 || x==rows-1 || y==0 || y==cols-1)
                {
                    disjointSets->Union(dummyBorder, borderO); 
                    continue; 
                }

                for(vector<int> dir : directions)
                {
                    int nx = x + dir[0]; 
                    int ny = y + dir[1]; 

                    if(nx >=0 && ny >=0 && nx < rows && ny < cols && board[nx][ny]=='O'){
                        int neighbor = nx*cols + ny; 
                        disjointSets->Union(borderO, neighbor); 
                    }
                }
            }
        }
    } 

    for(int x = 0; x < rows; x++)
    {
        for(int y=0; y<cols; y++)
        {
            if(board[x][y] == 'O' && disjointSets->find(x*cols+y) != disjointSets->find(dummyBorder))
            board[x][y] = 'X'; 
        }
    }
}
int main()
{
    vector<vector<char>>board ={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    solve(board); 

    int rows = board.size(); 
    int cols = board[0].size(); 

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        cout<<board[i][j]<<" "; 

        cout<<endl; 
    }
    return 0; 
}