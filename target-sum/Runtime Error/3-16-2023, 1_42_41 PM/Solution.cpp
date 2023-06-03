// https://leetcode.com/problems/target-sum

class Solution {
public:
    int solve(vector<int>& arr, int k, int i, vector<vector<int>>& dp) {
        if(i==0)
        {
            if(k==0 && arr[0]==0) return 2;
            if(arr[0]==k || k==0) return 1;
            return 0;
        }

        if(dp[i][k] != -1) return dp[i][k];

        int dontPick = solve(arr, k, i-1, dp);
        int pick = 0;
        if(arr[i] <= k) pick = solve(arr, k-arr[i], i-1, dp);

        return dp[i][k] = dontPick + pick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int sum = 0;
        for(int num: nums) sum += num;

        if(sum - target < 0) return 0;
        if((sum - target) % 2 == 1) return 0; 
        int k = (sum - target) / 2;
        
        return solve(nums, k, n-1, dp);
    }
};