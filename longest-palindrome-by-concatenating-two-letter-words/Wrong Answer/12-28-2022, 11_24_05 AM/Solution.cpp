// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,bool> mp;
        int n = words.size();
        int length = 0;

        for(int i=0; i<n; i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            mp[words[i]] = 1;

            if(word == words[i] && (length == 0 || length % 4 == 0)) {
                length += 2;
                continue;
            }

            if(word != words[i] && mp.find(word) != mp.end()) {
                length += 4;
            }
        }  

        return length;
    }
};