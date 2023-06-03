// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    stack<vector<int>> st;

    st.push(intervals[0]);

    int k = 0;
    for (int i = 1; i < n; i++)
    {
        vector<int> curr = st.top();
        st.pop();

        vector<int> temp(2);
        if (curr[1] >= intervals[i][0])
        {
            temp[0] = min(intervals[i][0], curr[0]);
            temp[1] = max(intervals[i][1], curr[1]);
        }
        else
        {
            st.push(curr);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
        }
        st.push(temp);
    }
    
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
    }
};