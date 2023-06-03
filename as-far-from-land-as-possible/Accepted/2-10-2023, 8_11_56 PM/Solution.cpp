// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // multisource breadth first search
        int n = grid.size();
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }

        int ans = -1;
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()) {
            pair<int,int> temp = q.front();
            int r = temp.first;
            int c = temp.second;
            q.pop();

            ans = grid[r][c];
            for(int i=0; i<dir.size(); i++) {
                int dr = dir[i].first;
                int dc = dir[i].second;
                
                int newR = r+dr;
                int newC = c+dc;

                if(min(newR, newC) >= 0 && max(newR, newC) < n && grid[newR][newC] == 0) {
                    q.push({newR, newC});
                    grid[newR][newC] = grid[r][c] + 1;
                }
            }
        }

        return ans > 1 ? ans - 1 : -1;
    }
};