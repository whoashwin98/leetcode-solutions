// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right) {
            if(nums[left] > nums[right]) {
                left++;
            }
            
            else {
                break;
            }
        }
        
        return nums[left];
        
    }
};