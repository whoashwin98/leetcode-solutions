// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool solve(string s, string p, int i, int j) {
        // base cases
        if(j < 0 && i < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k<=j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?') {
            return solve(s,p,i-1,j-1);
        }

        if(p[j] == '*') {
            return solve(s, p, i, j-1) || solve(s, p, i-1, j);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return solve(s, p, n-1, m-1);
    }
};