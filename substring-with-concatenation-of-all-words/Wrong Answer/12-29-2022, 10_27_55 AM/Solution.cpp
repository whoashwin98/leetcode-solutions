// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;

        for(string word : words) mp[word]++;

        int windowSize = words.size() * words[0].size();
        
        int start = 0;
        int end = windowSize - 1;
        vector<int> ans;

        while(end < s.size()) {
            unordered_map<string, int> chk(mp);

            int i = start;
            int wordSize = words[0].size();
            bool flag = true;
            while(i <= end) {
                string str = s.substr(i,wordSize);
                if(chk[str] == 0) {
                    flag = false;
                    break;
                }
                chk[str]--;
                i += wordSize;
            }

            if(flag) ans.push_back(start);

            start += words[0].size();
            end += words[0].size();
        }

        return ans;
    }
};