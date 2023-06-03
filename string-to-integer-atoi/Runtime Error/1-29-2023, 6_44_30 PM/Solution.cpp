// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
    void solve(int& ans, string str, int i) {
        if(i < 0) return;

        if(str[i] == '-') ans = -1 * ans;
        else ans += ((str[i] - '0') * pow(10,(str.size()-i-1)));
        
        solve(ans,str,i-1);
    }
  
public:
    int myAtoi(string s) {
        // ignore leading space and anything after the digits.
        bool firstDigit = false;

        string str = "";

        int i=0; 
        while(i < s.size()) {
            if(s[i] == ' ') i++;
            else if(s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) break;
            else return 0;
        }

        // the first character is a minus or number
        str.push_back(s[i]);
        i++;

        while(i < s.size()) {
            if((s[i] >= '0' && s[i] <= '9')) {
                str.push_back(s[i]);
            }
            else break;
            i++;    
        }

        cout << str;
        int ans = 0;
        solve(ans, str, str.size()-1);
        return ans;
    }
};