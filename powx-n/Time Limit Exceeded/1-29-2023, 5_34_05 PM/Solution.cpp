// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        if(n == 0) return 1;

        if(n < 0) {
            x = 1/x;
            n = abs(n);
        }
        
        while(n > 0) {
            ans = ans * x;
            n--;
        }

        return ans;
    }
};