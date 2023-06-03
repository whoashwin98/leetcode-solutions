// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
    bool isValid(char ch) {
        if(ch >= '0' && ch <= '9') return true;
        else if(ch == ' ') return true;
        else if(ch == '-') return true;
        else return false;
    }

public:
    int myAtoi(string s) {
        int n = s.size();
        int ans = 0;
        const int M = 2147483647;
        bool sign = false;

        if(!isValid(s[0])) return false;

        for(int i=0; i<n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans = (((ans%M) * 10)%M + (s[i] - '0'))%M;
            }
            else if(s[i] == '-') sign = true;
            else continue;
        }  

        if(sign) ans = (-1 * (ans%M))%M;
        return ans;
    }
};