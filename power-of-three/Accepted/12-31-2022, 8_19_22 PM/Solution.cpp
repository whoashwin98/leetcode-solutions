// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;

        long long i=1;
        while(i <= n) {
            if(n == i) return true;
            i = i*3;
        }

        return false;
    }
};