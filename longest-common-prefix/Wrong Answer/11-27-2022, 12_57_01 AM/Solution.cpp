// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];

        int n = strs.size();
        for(int i=0; i<n; i++) {
            bool flag = true;
            int j;
            for(j=0; j<n-1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    flag = false;
                    break;
                }
            }

            if(flag) ans += strs[i][i];
        }
        return ans;
    }
};