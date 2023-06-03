// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        
        int i=0;
        int n = s.length();
        while(i < n - 1) {
            if(s[i] == s[i+1]) {
                int j=i+1;
                while(j<n-1 && s[j] == s[j+1]) {
                    j++;
                    cout << j << endl;
                }               
                
                if((j+1) == n && i==0) s.clear();
                else s.erase(i,j-i+1);
                i=0;
                n = s.length();
            }    
            else i++;
        }
        
        return s;
        
    }
};