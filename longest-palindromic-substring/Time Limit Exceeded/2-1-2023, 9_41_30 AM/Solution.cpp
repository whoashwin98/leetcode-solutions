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

        if(ans == "") ans += s[0];
        return ans;
    }
};

/*
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.
*/