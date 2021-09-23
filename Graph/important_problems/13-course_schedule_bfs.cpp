//based on kahn's algorithm 


//https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/
//https : //leetcode.com/problems/course-schedule/

// find whether it is possible to finish all tasks or not from given dependencies

bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n); 
        
        int m = pre.size(); 
        
        vector<int> in_degree(n, 0); 
        
        for(int i=0; i<m; i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]); 
            in_degree[pre[i][0]]++; 
        }
        
        queue<int>q; 
        for(int i=0; i<n; i++)
            if(in_degree[i]==0)q.push(i); 
        
        int count = 0; 
        
        while(!q.empty())
        {
            int x = q.front(); 
            q.pop(); 
            count++; 
            
            for(auto y : adj[x])
            {
                if(--in_degree[y] == 0)
                    q.push(y); 
            }
        }
        //based on kahn's algorithm, that if the number of edges processed is not equal to n, then there must be a cycle. 
        return n==count ? true : false; 
    }
