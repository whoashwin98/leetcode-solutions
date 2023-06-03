// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;

        long long i=1;
        while(i <= n) {
            if(n == i) return true;
            i = i << 2;
        }

        return false;
    }
};