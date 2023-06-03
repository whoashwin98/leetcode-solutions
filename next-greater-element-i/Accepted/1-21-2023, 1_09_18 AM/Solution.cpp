// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--) {
            while(st.top() != -1 && st.top() <= nums2[i]) st.pop();
            ans[i] = st.top();
            st.push(nums2[i]);
        }

        vector<int> result(m);
        for(int i=0; i<m; i++) {
            int j = 0;
            while(j < n && nums1[i] != nums2[j]) j++;
            result[i] = ans[j];
        }

        return result;
    }
};