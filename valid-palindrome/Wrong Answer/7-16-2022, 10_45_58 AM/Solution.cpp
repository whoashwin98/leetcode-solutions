// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                temp.push_back(tolower(s[i]));
            } else if(s[i] >= 'a' && s[i] <= 'z'){
                temp.push_back(s[i]);
            } 
        }
        int i=0, j=temp.size()-1;
        while(i<j) {
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};