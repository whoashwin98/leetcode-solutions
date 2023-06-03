// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
            if(n == 1) return true;

    int i=1;
    while(i > 0) {
        if(n == i) return true;
        i = i << 1;
    }

    return false;
    }
};