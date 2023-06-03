// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        if(s == "") return 0;

        int i=0;
        while(i < s.size() && s[i] == ' ') i++;

        if(i == s.size()) return 0;

        int ans = 0;
        for(; i<s.size(); i++) {
            if(s[i] == ' ') ans++;
        }

        ans++;
        return ans;
    }
};