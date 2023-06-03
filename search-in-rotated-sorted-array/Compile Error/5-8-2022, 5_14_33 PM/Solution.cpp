// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int findMinIndex(vector<int>& nums) {
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
        return left;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = findMinIndex(nums);
        int left = 0;
        int right = nums.size()-1;
        
        if(nums[pivot] == target) {
            return pivot;
        }
        
        else if (nums[left] < target && target < nums[pivot]) {

        }
        
        else {

        }
    }
};