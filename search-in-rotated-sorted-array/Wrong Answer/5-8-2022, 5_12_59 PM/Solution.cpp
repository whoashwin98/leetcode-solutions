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
    
    int bs(vector<int> &nums, int low, int high, int target) {
        while(low < high) {
            int mid = low+high/2;
            if(nums[mid] == target) {
                return mid;
            }
            
            else if(nums[mid] < target) {
                low = mid+1;
            }
            
            else {
                high=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = findMinIndex(nums);
        int left = 0;
        int right = nums.size()-1;
        
        if(nums[pivot] == target) {
            return pivot;
        }
        
        else if (nums[left] < target && target < nums[pivot]) {
            return bs(nums,left,pivot-1,target);
        }
        
        else {
            return bs(nums,pivot,right,target);
        }
    }
};