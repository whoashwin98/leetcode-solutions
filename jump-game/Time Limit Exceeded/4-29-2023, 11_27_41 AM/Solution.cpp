// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int> nums, int index) {
        if(index == 0) return true;

        for(int i = index-1; i>=0; i--) {
            if(nums[i] >= index - i) {
                if(solve(nums, i)) return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        return solve(nums, n-1);
    }
};