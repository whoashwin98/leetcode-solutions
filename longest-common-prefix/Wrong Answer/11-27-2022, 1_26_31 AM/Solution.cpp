// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        string first = strs[0];
        int k = 0;
        for(int i=1; i<=first.size(); i++) {
            string sub = first.substr(0,i);
            int j;
            for(j=1; j<strs.size(); j++) {
                if(strs[j].find(sub,0) == string::npos) break;
            }
            
            if(j == strs.size()) {
                ans += strs[0][k++];
            }
        }

        return ans;
    }
};