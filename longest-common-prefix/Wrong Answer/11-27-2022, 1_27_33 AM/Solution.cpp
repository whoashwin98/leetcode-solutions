// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        string first = strs[0];
        int k = 0;
        bool flag = true;
        for(int i=1; i<=first.size(); i++) {
            string sub = first.substr(0,i);
            int j;
            for(j=1; j<strs.size(); j++) {
                if(strs[j].find(sub,0) == string::npos) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                ans += strs[0][k++];
            }
        }

        return ans;
    }
};