// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = s1.size();

        unordered_map<char, int> mp;

        for(char ch: s1) mp[ch]++;

        while(right < s2.size()) {
            string curr = s2.substr(left, right-left+1);
            
            unordered_map<char,int> chars(mp);
            for(char ch : curr) {
                if(chars.find(ch) == chars.end()) break;
                chars[ch]--;
                if(chars[ch] == 0) chars.erase(ch);
            }

            if(chars.empty()) return true;

            left++;
            right++;
        }

        return false;
    }
};