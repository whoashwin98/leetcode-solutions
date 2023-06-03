// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int result = 0;
        int number = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c >= '0' && c <= '9') {
                number = 10 * number + (int)(c - '0');
            } else if(c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if(c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if(c == '(') {
                //we push the result first, then sign;
                stack.push(result);
                stack.push(sign);
                //reset the sign and result for the value in the parenthesis
                sign = 1;   
                result = 0;
            } else if(c == ')') {
                result += sign * number;  
                number = 0;
                result *= stack.top();    //stack.pop() is the sign before the parenthesis
                stack.pop();
                result += stack.top();   //stack.pop() now is the result calculated before the parenthesis
                stack.pop();
            }
        }

        if(number != 0) result += sign * number;
        return result;
    }
};