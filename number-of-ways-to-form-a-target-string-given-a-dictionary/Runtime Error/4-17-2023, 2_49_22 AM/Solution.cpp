// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution {
public:
    // recursion + memoization solution here
    int solve(vector<string>& words, string target, int k, int j, vector<vector<int>>& dp) {
        // base cases
        if(j == target.size()) return 1;
        if(k == words[0].size() || words[0].size() - k < target.size() - j) return 0;

        if(dp[k][j] != -1) return dp[k][j];

        int count = 0;
        // not picking the current positioned character from dictionary
        count += solve(words, target, k+1, j, dp);
        
        // picking each character from current position one at a time
        for(int i=0; i<words.size(); i++) {
            if(words[i][k] == target[j]) {
                count += solve(words, target, k+1, j+1, dp);
            }
        }

        return dp[k][j] = count;
    }

    int numWays(vector<string>& words, string target) {
        int m = words[0].size();
        int n = target.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(words, target, 0, 0, dp);
    }
};