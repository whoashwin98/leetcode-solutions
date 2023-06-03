// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxAns = 0;

        while(left < n) {
            char ch = s[left];
            right = left+1;
            int repl = 0;

            while(right < n && repl < k) {
                if(s[right] != ch) repl++;
                right++;
            }

            if(right == n) right--;
            maxAns = max(maxAns, right - left + 1);
            left++;
        }

        return maxAns;
    }
};