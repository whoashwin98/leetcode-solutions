// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_map<char,int> mp;
        int maxCount = 0;
        int ans = 0;

        while(right < s.size()) {
            mp[s[right]]++;
            maxCount = max(maxCount, mp[s[right]]);

            if((right-left+1) - maxCount > k) {
                mp[s[left]]--;
                left++;
            }

            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};