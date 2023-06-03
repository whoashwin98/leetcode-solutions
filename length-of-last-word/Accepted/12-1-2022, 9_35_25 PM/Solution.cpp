// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int len = 0;
        bool afterChar = false;

        while(i >= 0) {
            if(s[i] != ' ') {
                len++;
                afterChar = true;
            }
            else if(afterChar && s[i] == ' ') break;
            i--;
        }

        return len;
    }
};