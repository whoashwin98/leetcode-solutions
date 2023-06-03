// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' );
    }

    void swapStr(string& s, int left, int right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(isVowel(s[left]) && isVowel(s[right])) {
                swapStr(s, left, right);
                left++;
                right--;
            }

            else if(!isVowel(s[right])) right--;
            else if(!isVowel(s[left])) left++;
        }

        return s;
    }
};