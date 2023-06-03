// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    void solve(string s, string t, string& ans, int i, bool& flag) {
        if(i == t.size()) {
            if(ans == s) flag = true;
            return;
        }

        ans.push_back(t[i]);
        solve(s,t,ans,i+1,flag);
        ans.pop_back();
        solve(s,t,ans,i+1,flag);
    }

    bool isSubsequence(string s, string t) {
        string ans = "";
        bool flag = false;
        solve(s,t,ans,0,flag);
        return flag;
    }
};