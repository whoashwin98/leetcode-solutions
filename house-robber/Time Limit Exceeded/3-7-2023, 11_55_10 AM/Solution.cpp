// https://leetcode.com/problems/house-robber

class Solution {
public:
    int solve(vector<int>& nums, int index) {
        if(index < 0) return 0;
        if(index == 0) return nums[0];

        int pick = nums[index] + solve(nums, index-2);
        int dontPick = solve(nums, index-1);

        return max(pick, dontPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n-1);
    }
};