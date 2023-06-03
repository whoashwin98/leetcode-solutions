// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > i; j--) {
                if (2 * nums[i] <= nums[j]) ans++;
            }
        }
        
        return ans;
    }
};