// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    int findMinPos(vector<int> nums) {
        int idx = 1;

        while(idx < nums.size()-1) {
            if(nums[idx-1] <= nums[idx]) idx++;
            else break;
        }

        return idx;
    }

    bool search(vector<int>& nums, int target) {
        int pivot = findMinPos(nums);
        int n = nums.size();

        if(n == 1) {
            if(nums[n-1] == target) return true;
            else return false;
        } 

        int low, high;

        if(target >= nums[pivot] && target < nums[n-1]) {
            low = pivot; high = n-1;
        }

        else {
            low = 0; high = pivot;
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