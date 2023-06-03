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
            if(isVowel(s[i])) len++;
            if(i >= k && isVowel(s[i-k])){
                len--;
            }
            ans = max(ans, len);
        }

        return ans;
    } 
};