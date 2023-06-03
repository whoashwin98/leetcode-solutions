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
            int noOfWords = words.size();
            int wordsUsed = 0;
            
            while(i <= end) {
                string str = s.substr(i,wordSize);
                if(chk[str] <= 0) break;
                chk[str]--;
                wordsUsed++;
                i += wordSize;
            }

            if(wordsUsed == noOfWords) ans.push_back(start);
            start++;
            end++;
        }

        return ans;
    }
};