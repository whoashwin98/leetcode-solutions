// https://leetcode.com/problems/01-matrix

class Solution {
public:
    void bfs(vector<vector<int>>& mat, int row, int col, vector<vector<int>>& vis) {
        int n = mat.size();
        int m = mat[0].size();
        
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});

        vector<pair<int,int>> dir{{-1,0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto d : dir) {
                int newr = r + d.first;
                int newc = c + d.second;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && mat[newr][newc] == 1) {
                    vis[newr][newc] = 1;
                    mat[newr][newc] += mat[r][c];
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) {
                    bfs(mat, i, j, vis);
                }
            }
        }

        return mat;
    }
};