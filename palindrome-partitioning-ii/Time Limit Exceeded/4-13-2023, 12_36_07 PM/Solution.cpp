// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }


    int solve(string s, int n, int i) {
        if(i == n) return 0;

        int mini = INT_MAX;
        for(int j=i; j<n; j++) {
            int cost = 1e9;
            if(isPalindrome(s, i, j)) {
                cost = 1 + solve(s, n, j+1);
                mini = min(cost, mini);
            }
        }

        return mini;
    }

    int minCut(string s) {
        int n = s.size();
        return solve(s, n, 0) - 1;
    }
};