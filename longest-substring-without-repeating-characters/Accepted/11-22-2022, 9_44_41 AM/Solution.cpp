// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> hset;
        int start = -1;
        int end = -1;
        int ans = INT_MIN;
        int count = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
            char c = s[i];
            if (hset.find(c) == hset.end()) {
                end = i;
                hset[c] = true;
                count++;
                if (start == -1)
                    start = i;
            }
            else {
                ans = max(ans,count);
                count--;
                char curr = s[start];
                hset.erase(curr);
                start++;
                i--;
            }
        }

        ans = max(ans,count);
        
        return ans;
    }
};