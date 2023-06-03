// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution {
public:
    long solve(vector<string>&words, string &target, int i, int j, vector<vector<int>>& dp, vector<vector<int>> freq){

        if(j == target.size()) return 1;
        if(i == words[0].size() || words[0].size() - i < target.size() - j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long count = 0;
        int  curPos = target[j] - 'a';
        count += solve(words, target, i + 1, j, dp, freq);
        count += freq[i][curPos] * solve(words, target, i + 1, j + 1, dp, freq);
        return dp[i][j] = count % 1000000007;
    }

    int numWays(vector<string>& words, string target) {
        int m = words[0].size();
        int n = target.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        vector<vector<int>> freq(m, vector<int>(26, 0));
        for(int i=0; i<words.size(); i++){
            for(int j = 0; j < words[0].size(); j++){
                int  curPos = words[i][j] - 'a';
                freq[j][curPos]++;
            }
        }

        return solve(words,target,0,0,dp,freq);
    }
};