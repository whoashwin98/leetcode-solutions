// https://leetcode.com/problems/restore-ip-addresses

class Solution {
    void solve(string s, vector<string>& ips, vector<string>& ans, int i) {
        if(i == s.size() && ips.size() == 4) {
            string ip = ips[0] + "." + ips[1] + "." + ips[2]  + "." + ips[3];
            ans.push_back(ip);
            return;
        }

        else if(i == s.size() || ips.size() == 4) return;

        for(int len = 1; len <= 3 && i + len <= s.size(); len++) {
            string num = s.substr(i,len);

            if((stoi(num) > 255) || (num.size() > 1  && num[0] == '0')) break;;

            ips.push_back(num);
            solve(s,ips,ans,i+len);
            ips.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        vector<string> ans;
        int i=0;
        solve(s,ips,ans,i);
        return ans;
    }
};