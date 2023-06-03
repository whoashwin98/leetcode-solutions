// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        long long orig = x;
        long long rev = 0;

        while(x > 0) {
            int dig = x % 10;
            rev = rev * 10 + dig;
            x = x/10;
        }

        return orig == rev;
    }
};