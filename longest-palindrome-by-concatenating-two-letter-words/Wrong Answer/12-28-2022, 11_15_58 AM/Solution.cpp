// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int n = words.size();

        for(int i=0; i<n; i++) {
            mp[words[i]]++;
        }   

        int length = 0;
        for(auto it : mp) {
            string word = it.first;
            reverse(word.begin(), word.end());

            if(word == it.first && (length == 0 || length % 4 == 0)) {
                length += 2;
                continue;
            }

            if(word != it.first && mp.find(word) != mp.end() && mp[word] == mp[it.first]) {
                length += mp[word] * 2;
            }
        }

        return length;
    }
};