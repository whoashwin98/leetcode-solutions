// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int p = s.size() - 1;
        for(int i=0; i<s.size(); i++) {
            ans += pow(26,p) * (s[i]-'A'+1);
            p--;
        }
        return ans;
    }
};