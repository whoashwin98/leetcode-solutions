// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        
        int dig = 0;
        int x1 = 0;
        
        while (x > 0) {
            dig = x%10;
            x1 = x1*10 + dig;
            x/=10;
        }
        
        return x1;
    }
};