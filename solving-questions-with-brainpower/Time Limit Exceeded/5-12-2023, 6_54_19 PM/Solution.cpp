// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    long long solve(vector<vector<int>> questions, int i) {
        if(i >= questions.size()) return 0;

        int skip = 0 + solve(questions, i+1);
        int attempt = 0;
        if(i < questions.size()) attempt = questions[i][0] + solve(questions, i + questions[i][1] + 1);

        return max(skip, attempt);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return solve(questions, 0);
    }
};