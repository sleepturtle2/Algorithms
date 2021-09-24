//https://www.geeksforgeeks.org/find-the-number-of-islands-set-2-using-disjoint-set/
//https://leetcode.com/problems/number-of-islands/


    class DisjointSet
    {
        public: 
        vector<int> parent; 
        vector<int>rank; 
        int n; 
        DisjointSet(int n)
        {
            this->n = n; 
            parent.resize(n); 
            rank.resize(n); 
            iota(parent.begin(), parent.end(), 0); 
            fill(rank.begin(), rank.end(), 0); 
        }
        
        inline int find(int x)
        {
            if(x==parent[x])
                return x; 
            return parent[x] = find(parent[x]); 
        }
        
        inline bool unite(int x, int y)
        {
            x = find(x); 
            y = find(y); 
            if(x!=y)
            {
                if(rank[x] < rank[y]){
                    swap(x,y); 
                }
                parent[y] = x; 
                
                if(rank[x] == rank[y]){
                    rank[x]++; 
                }
                return true; 
            }
            
            return false; //if x = y
        }
        
    };
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        if(n==0) return 0; 
        
        int m = grid[0].size(); 
        if(m==0) return 0; 
        DisjointSet d(n*m); 
        
        auto inside = [&](int i, int j){
            return ((i>=0 && i<n) && (j>=0 && j<m)); 
        }; 
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int x=-1; x<=1; x++){
                    for(int y=-1; y<=1; y++)
                    {
                        if(abs(x+y) != 1) continue; 
                        
                        int xx = i + x; 
                        int yy = j + y; 
                        
                        if(inside(xx, yy)){
                            if(grid[i][j] == grid[xx][yy]){
                                d.unite(xx*m + yy, i*m + j); 
                            }
                        }
                    }
                }
            }
        }
        d.print(); 
        int ans = 0; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && d.find(i*m + j) == i*m + j){
                    cout<<i<<" "<<j<<" "<<d.find(i*m+j)<<endl; 
                    ans++; 
                }
            }
        }
        
        return ans; 
    }
