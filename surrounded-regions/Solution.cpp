class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<pair<int,int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O') q.push({0,j});
            if(board[m-1][j] == 'O') q.push({m-1,j});
        }
        
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][n-1] == 'O') q.push({i,n-1});
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            vis[node.first][node.second] = 1;

            for(auto d : dir) {
                int newr = d.first + node.first;
                int newc = d.second + node.second;

                if(newr >= 0 && newr < m && newc >= 0 && newc < n && !vis[newr][newc] && board[newr][newc] == 'O') {
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};