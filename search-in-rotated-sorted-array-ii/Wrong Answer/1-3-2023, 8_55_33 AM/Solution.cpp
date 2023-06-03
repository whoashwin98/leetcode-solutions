// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    int findMinPos(vector<int> nums) {
        int mini = INT_MAX;
        int idx = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                idx = i;
            }
        }

        return idx;
    }

    bool search(vector<int>& nums, int target) {
        int pivot = findMinPos(nums);
        int n = nums.size();

        if(n == 1 && target == nums[n-1]) return true;

        int low, high;

        if(target >= nums[pivot] && target < nums[n-1]) {
            low = pivot; high = n-1;
        }

        else {
            low = 0; high = pivot-1;
        }

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
};