// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = -32768; 
        int currsum = 0;
        for(int i=0; i<n; i++) {

        currsum += nums[i];

        maxsum = max(maxsum,currsum);

        if(currsum < 0) {
            currsum = 0;
        }
      }
        return maxsum;
    }
};