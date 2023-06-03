// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        
        for(int i=1; i<n; i++) {
            ans = ans ^ nums[i];
        }
        
        for(int i=1; i<=n-1; i++) {
            ans = ans ^ i;
        }
        
        return ans;
    }
};