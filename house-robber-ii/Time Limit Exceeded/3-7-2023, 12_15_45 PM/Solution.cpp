// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int solve(vector<int> nums, int index, int base) {
        // note that 0 and n-1 are adjacent as well
        // rob 1 to n-2 or 2 to n-1
        if(index < base) return 0;
        if(index == base) return nums[base];

        int pick = solve(nums, index-2, base) + nums[index];
        int dontPick = solve(nums, index-1, base);
        return max(pick, dontPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(nums, n-1, 1), solve(nums, n-2, 0));
    }
};