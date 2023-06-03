// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    void solve(string digits, string output, int i, vector<string>& ans) {
        // base case
        if(i == digits.length()) {
            ans.push_back(output);
            return;
        }

        // storing the mapping of each digit in a vector of strings (0 and 1 have empty strings)
        vector<string> maps = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // knowing which letters to be used from the digits
        string letters = maps[digits[i] - '0'];

        for(int j=0; j<letters.length(); j++) {
            // now for each letter, we push it to the answer, recursively call for the next index
            output.push_back(letters[j]);
            solve(digits,output,i+1,ans);
            // while coming back we pop out the pushed character to insert the next
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) {
            return ans;
        }

        int i=0;
        string output = "";
        solve(digits,output,i,ans);
        return ans;
    }
};