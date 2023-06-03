// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
    bool isPalindrome(string str) {
        if(str == "") return true;
        string rev = str;
        reverse(rev.begin(), rev.end());
        return rev == str;
    }

public:
    string longestPalindrome(string s) {
        string ans = "";
        if(s.length() == 1) return s;
        
        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                string sub = s.substr(i,j-i+1);
                if(isPalindrome(sub) && sub.size() > ans.size()) ans = sub;
            }
        }

        return ans;
    }
};