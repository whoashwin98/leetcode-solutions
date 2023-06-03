// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution {
public:

    int solve(vector<string>& words, string target, int k, int j) {
        // base cases
        if(j == target.size()) return 1;
        if(k == words[0].size()) return 0;

        int count = 0;
        // not picking the current positioned character from dictionary
        count += solve(words, target, k+1, j);
        
        // picking each character from current position one at a time
        for(int i=0; i<words.size(); i++) {
            if(words[i][k] == target[j]) {
                count += solve(words, target, k+1, j+1);
            }
        }

        return count;
    }

    int numWays(vector<string>& words, string target) {
        return solve(words, target, 0, 0);
    }
};