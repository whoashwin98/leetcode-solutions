// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        st.push(-1);
        int n = temperatures.size();
        vector<int> ans(n,0);

        for(int i=n-1; i>=0; i--) {
            while(st.top() != -1 && temperatures[st.top()] <= temperatures[i]) st.pop();
            ans[i] = st.top() == -1 ? 0 : st.top()-i;
            st.push(i);
        }
        
        return ans;
    }
};