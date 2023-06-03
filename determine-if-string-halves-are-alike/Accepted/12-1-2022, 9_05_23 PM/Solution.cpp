// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;

        return false;
    }

    bool halvesAreAlike(string s) {
        int len = s.length() / 2;
        int firstCount = 0;
        for(int i=0; i<len; i++) {
            if(isVowel(s[i])) firstCount++;
        }

        int secondCount = 0;
        for(int i=len; i<s.length(); i++) {
            if(isVowel(s[i])) secondCount++;
        }

        return firstCount == secondCount;
    }
};