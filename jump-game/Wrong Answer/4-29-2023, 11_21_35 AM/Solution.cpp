// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool solve(vector<int> nums, int index) {
        if(nums[index] == 0) return false;
        if(index >= nums.size() - 1) return true;

        int capacity = nums[index];
        for(int i=1; i<=capacity; i++) {
            if(solve(nums, index+i)) { return true; }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};