// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') ans++;
        }

        ans++;
        return ans;
    }
};