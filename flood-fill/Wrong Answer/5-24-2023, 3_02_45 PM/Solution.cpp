// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int src = image[sr][sc];

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int,int>> dir({{-1,0}, {0,1}, {1,0}, {0,-1}});

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()) { 
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            vis[r][c] = 1;
            image[r][c] = color;

            for(auto d : dir) {
                int newr = r + d.first;
                int newc = c + d.second;

                if(newr >= 0 && newr < n && newc >= 0 && newc < n && image[newr][newc] == src && !vis[newr][newc]) {
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }

        return image;
    }
};