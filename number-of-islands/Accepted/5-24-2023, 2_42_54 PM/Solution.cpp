// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        grid[i][j] = '2';
        q.push({i,j});
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto d: dir) {
                int row = node.first + d.first;
                int col = node.second + d.second;

                if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == '1') {
                    grid[row][col] = '2';
                    q.push({row, col});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int count = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }

        return count;
    }
};