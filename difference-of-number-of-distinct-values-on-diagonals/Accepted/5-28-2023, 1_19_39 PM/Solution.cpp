// https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            vector<int> row;
            for(int j=0; j<m; j++) {
                unordered_map<int,int> tl, rb;
                for(int r=i-1, c=j-1; r>=0 && c>=0; r--, c--) tl[grid[r][c]]++;
                for(int r=i+1, c=j+1; r<n && c<m; r++, c++) rb[grid[r][c]]++;
                int l = tl.size();
                int r = rb.size();
                row.push_back(abs(l-r));
            }
            ans.push_back(row);
        }
        return ans;
    }
};