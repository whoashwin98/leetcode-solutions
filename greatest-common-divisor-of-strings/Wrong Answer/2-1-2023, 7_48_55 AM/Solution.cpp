// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string callGCD(string a, string b) {
        int m = a.size();
        int n = b.size();
        string ans = "";
        for(int i=1; i<=n; i++) {
            string prefix = b.substr(0,i);
            int len = prefix.size();
            int j = 0;
            while(j<m) {
                if(prefix == a.substr(j,len)) j+=len;
                else break;
            }
            if(j >= m) ans = prefix;
        }
        return ans;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) return callGCD(str1, str2);
        else return callGCD(str2, str1);
    }
};