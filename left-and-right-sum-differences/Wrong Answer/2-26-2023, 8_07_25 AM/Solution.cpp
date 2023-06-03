// https://leetcode.com/problems/left-and-right-sum-differences

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftPrefix(size);
        vector<int> rightPrefix(size);
        
        leftPrefix[0] = nums[0];
        for(int i=1; i<size; i++) {
            leftPrefix[i] = leftPrefix[i-1] + nums[i];
        }
        
        rightPrefix[size-1] = nums[size-1];
        for(int i = size-2; i>=0; i--) {
            rightPrefix[i] = rightPrefix[i+1] + nums[i];
        }
        
        vector<int> ans;
        for(int i=0; i<size; i++) {
            int left = i+1 < size ? leftPrefix[i+1] : 0;
            int right = i-1 >=0 ? rightPrefix[i-1] : 0;
            ans.push_back(abs(left-right));
        }
        
        return ans;
    }
};