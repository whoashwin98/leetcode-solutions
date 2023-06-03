// https://leetcode.com/problems/optimal-partition-of-string

class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int count = 1;

        for(int i=0; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) {
                st.clear();
                count++;
            }
            st.insert(s[i]);
        }

        return count;
    }
};