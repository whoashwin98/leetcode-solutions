// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int minLen = nums.size() +1;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= k && left <=right)
            {
                minLen = min(minLen, right -left + 1);
                sum -= nums[left++];
            }   
        }
        return minLen == nums.size() + 1 ? 0 : minLen;
    }
};