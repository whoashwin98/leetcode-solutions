// https://leetcode.com/problems/alternating-digit-sum

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        vector<int> digits;
        while(n > 0) {
            int dig = n % 10;
            digits.push_back(dig);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        bool sign = false;
        for(int digit : digits) {
            if(sign) digit = -1 * digit;
            sum += digit;
            sign = !sign;
        }

        return sum;
    }
};