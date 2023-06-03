// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int n) {
        
    int rev = 0;
    int dig;
    while(n != 0) {
        dig = n%10;
        // condition for integer overfow
        if(rev > INT32_MAX / 10 || rev < INT32_MIN / 10) {
            return 0;
        }
        rev = rev*10 + dig;
        n/=10;
    }

        return rev;
    }
};