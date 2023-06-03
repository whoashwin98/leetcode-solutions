// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string ans = "";

        string word = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                words.push_back(word);
                word = "";
            }

            else word += s[i];
        }

        words.push_back(word);

        reverse(words.begin(), words.end());

        for(int i=0; i < words.size(); i++) {
            if(words[i] != "") {
                ans += words[i];
                ans += " ";
            }
        }

        int i=ans.size()-1;
        while(ans[i] == ' ') {
            ans.erase(ans.begin()+i);
            i = ans.size()-1;
        }

        return ans;
    }
};