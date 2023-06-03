// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        for(int i=0; i<pushed.size(); ) {
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }

            else {
                st.push(pushed[i]);
                i++;
            }
        }

        while(!st.empty() && st.top() == popped[j]) {
            st.pop(); j++;
        }

        return st.empty();
    }
};