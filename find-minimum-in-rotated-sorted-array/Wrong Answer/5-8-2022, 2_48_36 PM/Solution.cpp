// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int minElem = nums[0];
        long long n = nums.size();
        
        for(long long i=1; i<=n-2; i++) {
            if(nums[i] < nums[i-1] && nums[i] < nums[i] < nums[i+1]) {
                minElem = nums[i];
            }
        }
        
        if(nums[n-1] < minElem) {
            minElem = nums[n-1];
        }
        
        return minElem;
    }
};