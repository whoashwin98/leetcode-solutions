// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int i,j;
        int n = nums.size();
    i=n-2;
    while(i>=0) {
        if(nums[i] < nums[i+1]) break;
        i--;
    }

    j=n-1;
    while(j>i) {
        if(nums[i] < nums[j]) break;
        j--;
    }

    swap(nums[i],nums[j]);
    reverse(nums.begin()+i+1, nums.end());
    }
};