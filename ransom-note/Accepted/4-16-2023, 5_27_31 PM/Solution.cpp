// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        
        for(char ch : ransomNote)  mp[ch]++;

        for(char ch : magazine) {
            if(mp.find(ch) == mp.end()) continue;
            mp[ch]--;
            if(mp[ch] == 0) mp.erase(ch);
        }

        if(mp.empty()) return true;
        return false;
    }
};