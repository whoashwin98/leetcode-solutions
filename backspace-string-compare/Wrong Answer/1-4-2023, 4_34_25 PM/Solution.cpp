// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string s1 = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '#' && !s1.empty()) s1.pop_back();
            else s1.push_back(s[i]);
        }

        string t1 = "";
        for(int i=0; i<t.size(); i++) {
            if(t[i] == '#' && !t1.empty()) t1.pop_back();
            else t1.push_back(t[i]);
        }

        return s1 == t1;
    }
};