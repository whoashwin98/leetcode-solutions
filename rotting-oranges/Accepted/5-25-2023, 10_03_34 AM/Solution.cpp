// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int fresh = 0;
        // get all the rotten oranges to start the BFS
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }

                else if(grid[i][j] == 1) fresh++;
            }
        }

        // initialise the time variable to keep track of maximum time taken
        int time = 0;
        int count = 0;
        // initialise direction arrays for ease of computation
        vector<pair<int,int>> dir{{-1,0}, {0, 1}, {1, 0}, {0, -1}};
        // start the BFS
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);
            vis[r][c] = 2;

            for(auto d : dir) {
                int newr = r + d.first;
                int newc = c + d.second;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && 
                   vis[newr][newc] != 2 && grid[newr][newc] == 1) {
                       q.push({{newr, newc}, t+1});
                       vis[newr][newc] = 2;
                       count++;
                }
            }
        }

        if(count != fresh) return -1;
        return time;
    }
};