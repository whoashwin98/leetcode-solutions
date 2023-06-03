// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    int mid = low;

    while (mid < high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        else if(nums[mid] == 1) {
            mid++;
        }

        else if(nums[mid] == 2) {
            swap(nums[mid],nums[high]);
            mid++;
            high--;
        }
    }
    }
};