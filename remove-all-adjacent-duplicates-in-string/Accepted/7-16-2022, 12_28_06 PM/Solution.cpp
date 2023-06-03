// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        
        int i=0;
        int n = s.length();
        while(i < n - 1) {
            if(s[i] == s[i+1]) {
                s.erase(i,2);
                n = s.length();
            }
            i++;
        }    
        
        i = s.length()-1;
        while(i>=1) {
            if(s[i-1] == s[i]) {
                s.erase(i-1,2);
                n = s.length();
            }
            i--;
        }
        return s;
        
    }
};