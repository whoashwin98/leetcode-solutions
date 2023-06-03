// https://leetcode.com/problems/brick-wall

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;

        for(auto row: wall) {
            int rowPos = 0;
            for(int i=0; i<row.size()-1; i++) {
                rowPos += row[i];
                mp[rowPos]++;
            }
        }

        int ans = 0;
        for(auto it : mp) {
            ans = max(ans,it.second);
        }

        return wall.size()-ans;

    }
};