// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        for(int i=0; i<k-1; i++) {
            pop_heap(nums.begin(),nums.end()-i);
        }
        return nums[0];
    }
};