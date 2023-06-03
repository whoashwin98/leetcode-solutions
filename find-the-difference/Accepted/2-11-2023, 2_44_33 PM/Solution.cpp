// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;

        for(char ch : t) mp[ch]++;

        for(char ch : s) mp[ch]--;

        for(auto it : mp) {
            if(it.second == 1) return it.first;
        }

        return '$';
    }
};