// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>, int>> q;
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if(grid[i][j] == 0) {
	                q.push({{i,j}, 0});
	                vis[i][j] = 1;
	            }
	            
	            else vis[i][j] = 0;
	        }
	    }
	    
	    vector<pair<int, int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	    
	    while(!q.empty()) {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int di = q.front().second;
	        q.pop();
	        
	        dist[r][c] = di;
	        for(auto d : dir) {
	            int newr = r + d.first;
	            int newc = c + d.second;
	            
	            if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc]) {
	                vis[newr][newc] = 1;
	                q.push({{newr, newc}, di+1});
	            }
	        }
	    }
	    
	    return dist;
    }
};