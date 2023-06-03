// https://leetcode.com/problems/percentage-of-letter-in-string

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int occ = 0;
        int total = s.size();
        
        for(char ch : s) {
            if(letter == ch) occ++;
        }

        int ans = (occ * 100) / total;
        return ans;
    }
};