// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = k-1;
        int n = nums.size();
        int ans = INT_MAX;

        while(right < n) {
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int i=left; i<=right; i++) {
                maxi = max(maxi, nums[i]);
                mini = min(mini, nums[i]);
            }
            ans = min(ans, maxi-mini);
            right++;
            left++;
        }   

        return ans;
    }
};