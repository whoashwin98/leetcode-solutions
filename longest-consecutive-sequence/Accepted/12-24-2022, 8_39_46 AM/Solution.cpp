// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int,bool> present, checked;

        for(int num : nums) {
            present[num] = true;
        }

        int maxLen = 0;
        for(int num : nums) {
            if(!checked[num] && !present[num-1]) {
                int temp = num;
                int len = 0;
                while(present[temp]) {
                    checked[num] = true;
                    len++;
                    temp++;
                }
                maxLen = max(maxLen,len);
            }
        }
        return maxLen;
    }
};