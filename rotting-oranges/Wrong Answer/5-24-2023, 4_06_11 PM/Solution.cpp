// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    void bfs(vector<vector<int>>& grid, int row, int col, int& time) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int,int>> dir({{-1,0}, {0,1}, {1,0}, {0,-1}});

        queue<pair<pair<int,int>, int>> q;
        q.push({{row,col}, time});

        while(!q.empty()) { 
            auto node = q.front();
            q.pop();
            
            int r = node.first.first;
            int c = node.first.second;
            time = node.second;

            vis[r][c] = 1;
            grid[r][c] = 2;

            for(auto d : dir) {
                int newr = r + d.first;
                int newc = c + d.second;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && grid[newr][newc] == 1) {
                    q.push({{newr, newc}, time+1});
                    vis[newr][newc] = 1;
                }
            }
        }

    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    bfs(grid, i, j, time);
                    break;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};