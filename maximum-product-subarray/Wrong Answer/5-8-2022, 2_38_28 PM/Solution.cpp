// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1;
        int mini = 1;
        int overallMax = INT_MIN;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                maxi = maxi * nums[i];
                mini = min(1, mini*nums[i]);
            }
            
            else if(nums[i] == 0) {
                mini = maxi = 1;
            }
            
            else {
                maxi = max(mini * nums[i],1);
                mini = maxi *  nums[i];
            }
            
            overallMax = max(overallMax,maxi);
        }
        
        if(overallMax < 0) {
            overallMax = *max_element(nums.begin(), nums.end());
        }
        
        return overallMax;
    }
};