// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxSize = INT_MIN;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) continue;

            int j = i+1;
            while(j < n && nums[j] == 1) j++;
            maxSize = max(maxSize, j-i);
        }
        
        return maxSize;
    }
};