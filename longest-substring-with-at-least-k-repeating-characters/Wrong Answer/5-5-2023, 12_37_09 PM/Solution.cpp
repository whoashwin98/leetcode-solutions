// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = 0;
        int ans = 0;
        int n = s.size();

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) mp[s[i]]++;

        for(int i=0; i<n; i++) {
            if(mp[s[i]] >= k) {
                len++;
                ans = max(ans, len);
            }

            else {
                len = 0;
            }
        }

        return ans;
    }
};