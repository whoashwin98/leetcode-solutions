// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    long long solve(vector<vector<int>> questions, int i, vector<long long>& dp) {
        if(i >= questions.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int skip = 0 + solve(questions, i+1, dp);
        int attempt = 0;
        if(i < questions.size()) attempt = questions[i][0] + solve(questions, i + questions[i][1] + 1, dp);

        return dp[i] = max(skip, attempt);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(questions, 0, dp);
    }
};