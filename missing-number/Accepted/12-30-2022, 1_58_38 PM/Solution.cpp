// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int num: nums) ans = ans ^ num;
        for(int i=0; i<=nums.size(); i++) ans = ans ^ i;
        return ans;
    }
};