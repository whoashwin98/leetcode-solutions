// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        if(num / 10 == 0) return num;

        do {
            int temp = 0;
            while(num > 0) {
                int dig = num % 10;
                temp += dig;
                num /= 10;
            }
            num = temp;
        } while(num / 10 != 0);

        return num;
    }
};