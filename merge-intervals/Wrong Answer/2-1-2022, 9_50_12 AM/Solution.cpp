// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
           sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i-1][1] >= intervals[i][0]) {
            vector<int> temp;
            temp.push_back(intervals[i-1][0]);
            temp.push_back(intervals[i][1]);

            ans.push_back(temp);
        }

        else {
            ans.push_back(intervals[i]);
        }
    }

    return ans; 
    }
};