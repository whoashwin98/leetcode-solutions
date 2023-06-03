// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurr = 0;
        int overallMax = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            maxCurr += nums[i];
            overallMax = max(overallMax,maxCurr);
            if(maxCurr < 0) {
                maxCurr = 0;
            }

        }
        
        return overallMax;
    }
};