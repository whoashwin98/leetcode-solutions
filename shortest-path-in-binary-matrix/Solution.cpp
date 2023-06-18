class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        // no need for priority queue since the regular queue stores everything in an
        // increasing order when BFS is performed
        queue<vector<int>> q;
        q.push({0, 0, 1});

        // using the same grid for marking the nodes as visited
        grid[0][0] = 1;

        vector<vector<int>> dir = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node[0];
            int col = node[1];
            int dist = node[2];

            // if destination is reached then return the distance 
            if (row == n - 1 && col == n - 1) {
                return dist;
            }

            // check for all 8 directions
            for (const auto& d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                // if the new location is within limits and is reachable, push it into the queue
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol, dist + 1});
                }
            }
        }

        return -1;
    }
};