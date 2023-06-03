// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low < high) {
            if(nums[low] == target || nums[low] > target) return low;
            low++;
        }    
        return nums.size();
    }
};