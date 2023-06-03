// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z = 0, nz = 1;

        while(nz < n) {
            // finds first zero
            while(z < n && nums[z] != 0) z++;

            if(z == n) break;
            // finds first non-zero after first zero
            nz = z+1;
            while(nz < n && nums[nz] == 0) nz++;
            if(nz == n) break;

            // swap these indices
            swap(nums[z], nums[nz]);
        }
    }
};