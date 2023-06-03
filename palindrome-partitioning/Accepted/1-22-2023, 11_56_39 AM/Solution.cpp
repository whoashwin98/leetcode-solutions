// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> palindromes;
        vector<vector<string>> ans;
        solve(s,palindromes,ans,0);
        return ans;
    }

    void solve(string s, vector<string> palindromes, vector<vector<string>>& ans, int st) {
        if(st == s.size()) {
            ans.push_back(palindromes);
            return;
        }

        for(int i=st; i<s.size(); i++) {
            if(isPalindrome(s,st,i)) {
                string sub = s.substr(st,i-st+1);
                palindromes.push_back(sub);
                solve(s,palindromes,ans,i+1);
                palindromes.pop_back();
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