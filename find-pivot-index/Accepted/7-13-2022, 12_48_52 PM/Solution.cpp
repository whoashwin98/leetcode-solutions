// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    
    int pivotIndex(vector<int>& nums) {
        int prefSum[100000];
        prefSum[0] = 0;
        int n = nums.size();
        
        for(int i=1; i<=n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i-1];
        }

        for(int i=0; i<n; i++) {
            int leftSum = prefSum[i];
            int rightSum = prefSum[n] - prefSum[i] - nums[i];
            
            if(leftSum == rightSum) {
                return i;
            }
        }
        
        return -1;
        // 11
        // 28 - 6 - 11 = 11
    }
};