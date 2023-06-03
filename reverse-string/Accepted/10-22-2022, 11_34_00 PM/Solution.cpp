// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        
        for(char ch : s) st.push(ch);
        s.clear();
        while(!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
    }
};