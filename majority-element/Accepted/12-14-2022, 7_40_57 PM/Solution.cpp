// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxNum = -1, maxCount = -1;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > maxCount) {
                maxNum = nums[i];
                maxCount = mp[nums[i]];
            }
        }

        return maxNum;
    }
};