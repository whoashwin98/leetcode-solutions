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

        for(int i=0; i<k; i++) {
            if(isVowel(s[i])) len++;
        }

        int ans = -1;
        ans = max(ans, len);
        len = 0;

        for(int i=k; i<n; i++) {
            if(isVowel(s[i])) len++;
            else {
                ans = max(ans, len);
                len = 0;
            }
        }

        return ans;
    } 
};