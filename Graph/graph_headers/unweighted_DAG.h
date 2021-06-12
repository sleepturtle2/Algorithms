#include<bits/stdc++.h>
using namespace std; 


class Graph{
    public: 
    int V=6; 
    int E=7; 

    vector<vector<int>>adj = {
        {}, //0
        {}, //1
        {3,4}, //2
        {1}, //3
        {0,1}, //4
        {2,0} //5
    }; 
}; 