// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;

        for(char ch: s1) mp[ch]++;

        int m = s1.size();
        int n = s2.size();

        for(int i=0; i<=n-m; i++) {
            string curr = s2.substr(i, m);
            
            unordered_map<char,int> chars(mp);
            for(char ch : curr) {
                if(chars.find(ch) == chars.end()) break;
                chars[ch]--;
                if(chars[ch] == 0) chars.erase(ch);
            }

            if(chars.empty()) return true;
        }

        return false;
    }
};