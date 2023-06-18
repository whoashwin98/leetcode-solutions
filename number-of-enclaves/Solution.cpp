class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<pair<int,int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        for(int j=0; j<n; j++) {
            if(grid[0][j] == 1) q.push({0,j});
            if(grid[m-1][j] == 1) q.push({m-1,j});
        }
        
        for(int i=0; i<m; i++) {
            if(grid[i][0] == 1) q.push({i,0});
            if(grid[i][n-1] == 1) q.push({i,n-1});
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            vis[node.first][node.second] = 1;

            for(auto d : dir) {
                int newr = d.first + node.first;
                int newc = d.second + node.second;

                if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc] && grid[newr][newc] == 1) {
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }   

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};