// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,bool> mp;

        if(s.length() != t.length()) return false;

        for(char ch : s) {
            mp[ch] = true;
        }

        for(char ch : t) {
            if(mp[ch] == false) return false;
        }

        
        return true;
    }
};