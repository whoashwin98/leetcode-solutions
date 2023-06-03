// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {
            if(start == end) break;

            int mid = start + (end-start)/2;

            // left part - even odd
            if((mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid-1] == nums[mid])) start = mid+1;
            // right part - unique element + odd even
            else end = mid;
        }

        return nums[start];
    }
};