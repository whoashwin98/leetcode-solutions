// https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<pair<int,int>>> mp;
        vector<int> row(n);
        vector<int> col(m);
        vector<vector<int>> dp(n, vector<int>(m,0));

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                mp[mat[i][j]].push_back({i,j});
            }
        }

        for (auto i : mp){
            for (auto& [x,y]: i.second) dp[x][y] = 1 + max(row[x], col[y]);
            for (auto& [x,y]: i.second) {
                row[x] = max(row[x], dp[x][y]);
                col[y] = max(col[y], dp[x][y]);
            }
        }
  
        return *max_element(col.begin(),col.end());
    }
};