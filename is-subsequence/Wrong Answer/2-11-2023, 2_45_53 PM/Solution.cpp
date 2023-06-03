// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, int> mp;

        for(char ch : t) mp[ch]++;

        for(char ch : s) {
            if(mp.find(ch) == mp.end()) return false;
        }

        return true;
    }
};