// https://leetcode.com/problems/restore-the-array

class Solution {
public: 
    // recursion + memoization here
    int solve(const string& s, long k, int i, vector<int>& dp) {
        // base case -> Found a valid way
        if (i == s.size()) return 1; 
        // all numbers are in range [1, k] and there are no leading zeros -> So numbers starting with 0 mean invalid!
        if (s[i] == '0') return 0; 
        if (dp[i] != -1) return dp[i];
        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++) {
            // num is the value of the substring s[i..j]
            num = num * 10 + s[j] - '0'; 
            // num must be in range [1, k]
            if (num > k) break; 
            ans += solve(s, k, j + 1, dp);
            ans %= 1000000007;
        }
        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return solve(s, k, 0, dp);
    }
};