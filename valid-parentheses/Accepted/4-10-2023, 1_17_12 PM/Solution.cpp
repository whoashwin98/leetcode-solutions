// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(ch == '(' || ch =='{' || ch == '[')
                st.push(ch);
            
            else {
                if(st.empty()) return false;
                
                if((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}')) st.pop();
                
                else return false;
            }
        }
        
        if(!st.empty()) return false;
        return true;
    }
};