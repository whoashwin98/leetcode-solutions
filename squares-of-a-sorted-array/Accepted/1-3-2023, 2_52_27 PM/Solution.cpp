// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        for(int num : nums) ans.push_back(num*num);

        sort(ans.begin(), ans.end());
        return ans;
    }
};