// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()!=0 && s.find(part) != -1) {
            s.erase(s.find(part),part.length());
        }
        
        return s;
    }
};