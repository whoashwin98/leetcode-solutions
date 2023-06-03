// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        // searching for leftmost occurence
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int ans = -1;
        while(low <= high) {
                mid = low + (high-low)/2;
                if(nums[mid] == target) {
                    ans = mid;
                    high = mid-1;
                }
                else if(nums[mid] < target) low = mid+1;
                else high = mid-1;
        }
        res.push_back(ans);
        
        // searching for rightmost occurence
        low = 0;
        high = nums.size()-1;
        ans = -1;
        while(low <= high) {
                mid = low + (high-low)/2;
                if(nums[mid] == target) {
                    ans = mid;
                    low = mid+1;
                }
                else if(nums[mid] < target) low = mid+1;
                else high = mid-1;
        }
        res.push_back(ans);
        
        return res;
    }
};