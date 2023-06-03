// https://leetcode.com/problems/next-permutation

class Solution {
public:

    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) 
        {
            i--;
        }

        if (i <= 0) 
        {
            sort(nums.begin(),nums.end());
            return;
        }

        int j = nums.size() - 1;

        while (nums[j] <= nums[i - 1]) 
        {
            j--;
        }

        int temp = nums[i - 1];
        nums[i - 1] = nums[j];
        nums[j] = temp;

        j = nums.size() - 1;

        while (i < j) 
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }          
    }
};