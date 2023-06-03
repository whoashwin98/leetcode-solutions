// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int sum = nums[0];

        for(int i=1; i<n; i++) {
            sum += nums[i];
            ans = max(ans, (int)ceil(sum / (i+1)));
        }

        return ans;
    }
};