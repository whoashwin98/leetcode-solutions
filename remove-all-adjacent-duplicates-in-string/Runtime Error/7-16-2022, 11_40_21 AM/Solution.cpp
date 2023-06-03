// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        
        int i=0;
        while(i<s.length() - 1) {
            if(s[i] == s[i+1]) {
                int j=i+1;
                while(s[j] == s[j+1]) {
                    j++;
                }
                int count = j-i+1;
                if (count == s.length()) s.clear();
                else s.erase(i,count);
                i=0;
            }    
            else i++;
        }
        
        return s;
        
    }
};