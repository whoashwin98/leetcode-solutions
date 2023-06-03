// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int minIdx = INT_MAX;
        for(auto it : mp) {
            if(it.second == 1) {
                int idx = find(s.begin(), s.end(), it.first) - s.begin();
                minIdx = min(minIdx, idx);
            }
        }

        if(minIdx == INT_MAX) return -1;
        return minIdx;
    }
};