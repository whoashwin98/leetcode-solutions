// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        solve(s,ans,res,0);
        return ans;
    }
    
    void solve(string s, vector<vector<string>>& ans, vector<string>& res, int start) {
        if(start == s.length()) {
            ans.push_back(res);
            return;
        }
        
        for(int i=start; i<s.length(); i++) {
            if(isPalindrome(s,start,i)) {
                res.push_back(s.substr(start, i-start+1));
                solve(s,ans,res,i+1);
                res.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};