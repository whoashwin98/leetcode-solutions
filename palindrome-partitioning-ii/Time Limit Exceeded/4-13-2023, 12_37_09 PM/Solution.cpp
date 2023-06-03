// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }


    int solve(string s, int n, int i, vector<int>& dp) {
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int j=i; j<n; j++) {
            int cost = 1e9;
            if(isPalindrome(s, i, j)) {
                cost = 1 + solve(s, n, j+1, dp);
                mini = min(cost, mini);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, n, 0, dp) - 1;
    }
};