// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;

        for(char ch : s) mp[ch]++;

        for(char ch : t) {
            if(mp.find(ch) == mp.end()) return ch;
        }

        return ' ';
    }
};