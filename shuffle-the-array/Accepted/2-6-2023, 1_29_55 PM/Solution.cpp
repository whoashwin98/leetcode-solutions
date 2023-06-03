// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int first = 0;
        int second = n;
        
        while(second < 2*n) {
            ans.push_back(nums[first++]);
            ans.push_back(nums[second++]);
        }

        return ans;
    }
};