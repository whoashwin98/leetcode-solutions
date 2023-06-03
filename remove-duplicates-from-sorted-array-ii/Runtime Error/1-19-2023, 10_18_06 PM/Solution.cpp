// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;

        if(nums.size() <= 2) return nums.size();

        while(left < nums.size()) {
            int right = left+1;
            if(nums[left] == nums[right]) {
                int start = right+1;
                int end = start;
                while(end < nums.size() && nums[left] == nums[end]) end++;
                nums.erase(nums.begin() + start, nums.begin() + end);
            }
            left = right;
        }

        return nums.size();
    }
};