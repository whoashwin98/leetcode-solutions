// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    
    void solve(vector<string>& ans, int n, string output, int open, int close) {
        if(open == n && close == n) {
            ans.push_back(output);
            return;
        }
        
        if(open < n) {
            output.push_back('(');
            solve(ans,n,output,open+1,close);
            output.pop_back();
        }
        
        if(close < n && open > close) {
            output.push_back(')');
            solve(ans,n,output,open,close+1);
            output.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        solve(ans,n,output,0,0);
        return ans;
    }
};