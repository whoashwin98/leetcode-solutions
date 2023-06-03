// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        
        int i=0;
        while(i<s.length() - 1) {
            if(s[i] == s[i+1]) {
                int j=i+1;
                int count = 2;
                while(j<s.length()-1 && s[j] == s[j+1]) {
                    count++;
                    j++;
                }                
                if(count == s.length()) count = -1;
                s.erase(i,count);
                i=0;
            }    
            else i++;
        }
        
        return s;
        
    }
};