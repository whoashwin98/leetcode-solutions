// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0; i<tokens.size(); i++) {
            if(!isOperator(tokens[i])) {
                cout << stoi(tokens[i]) << " ";
                st.push(stoi(tokens[i]));
            }
            else {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res = 0;
                switch(tokens[i][0]) {
                    case '+' : res = op2 + op1; break;
                    case '-' : res = op2 - op1; break;
                    case '*' : res = op2 * op1; break;
                    case '/' : res = op2 / op1; break;
                }
                st.push(res);
            }
        }

        return st.top();
    }
};