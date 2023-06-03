// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int solve(string text1, string text2, int i1, int i2) {
        if(i1 == 0 && i2 == 0) return text1[0] == text2[0];
        if(i1 < 0 || i2 < 0) return -1e9;

        // if found both as same, move both i1 and i2 behind
        int found = -1e9;
        if(text1[i1] == text2[i2]) found = 1 + solve(text1, text2, i1-1, i2-1);

        // if not found, either move i1 or i2, and take the max out of both
        int notFound = 0 + max(solve(text1, text2, i1-1, i2), solve(text1, text2, i1, i2-1));

        return max(found, notFound);
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, text1.size()-1, text2.size()-1);
    }
};