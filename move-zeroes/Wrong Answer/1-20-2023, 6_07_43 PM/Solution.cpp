// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z = 0, nz = 1;

        while(nz < n-1) {
            // finds first zero
            while(z < n && nums[z] != 0) z++;
            
            // finds first non-zero after first zero
            nz = z+1;
            while(nz < n && nums[nz] == 0) nz++;

            // swap these indices
            swap(nums[z], nums[nz]);
        }
    }
};