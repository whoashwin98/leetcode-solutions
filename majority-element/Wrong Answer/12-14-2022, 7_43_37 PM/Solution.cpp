// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxNum = nums[0], maxCount = -1;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            maxNum = nums[i];
            if(maxNum == nums[i]) count++;
            else {
                count = 0;
                if(count > maxCount) maxCount = count;
            }
        }

        return maxNum;
    }
};