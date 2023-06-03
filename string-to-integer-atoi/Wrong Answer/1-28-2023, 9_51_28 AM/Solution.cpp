// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int ans = 0;
        const int M = 2147483647;
        bool sign = false;

        for(int i=0; i<n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans = (((ans%M) * 10)%M + (s[i] - '0'))%M;
            }

            else if(s[i] == '-') sign = true;
        }  

        if(sign) ans = (-1 * (ans%M))%M;
        return ans;
    }
};