// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void solve(string digits, string output, vector<string>& ans, int i) {
        if(i == digits.size()) {
            ans.push_back(output);
            return;
        }

        vector<string> maps = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string letters = maps[digits[i] - '0'];

        for(int j=0; j<letters.size(); j++) {
            output.push_back(letters[j]);
            solve(digits, output, ans, i+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string output = "";
        vector<string> ans;

        if(digits == "") return ans;

        solve(digits, output, ans, 0);
        
        return ans;
    }
};