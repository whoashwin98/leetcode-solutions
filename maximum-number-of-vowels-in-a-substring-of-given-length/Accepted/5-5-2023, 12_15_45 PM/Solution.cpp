// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        else return false;
    }

    int maxVowels(string s, int k) {
        int len = 0;
        int n = s.size();
        int ans = -1;

        for(int i=0; i<n; i++) {
            // if the current character is a vowel then increment the window size
            if(isVowel(s[i])) len++;
            // for the charcters going out of the window, if they are 
            // vowels then reduce length of vowels
            if(i >= k && isVowel(s[i-k])){
                len--;
            }

            // update the maximum length
            ans = max(ans, len);
        }

        return ans;
    } 
};