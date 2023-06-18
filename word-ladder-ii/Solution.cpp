class Solution {
public:
    void dfs(vector<vector<string>>& ans, vector<string>& seq, string word, unordered_map<string, int> mp, string beginWord) {
        if(word == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int level = mp[word];
        for(int i=0; i<word.size(); i++) {
            char temp = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word] == level-1) {
                    seq.push_back(word);
                    dfs(ans, seq, word, mp, beginWord);
                    seq.pop_back();
                }
            }
            word[i] = temp;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto word: wordList) {
            st.insert(word);
        }

        // step 1: find the minimum steps, and also store the word and the corresponding level in
        // which it has occurred
        queue<pair<string, int>> q;
        unordered_map<string, int> mp;
        q.push(make_pair(beginWord, 1));
        mp[beginWord] = 1;
        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord) break;

            for(int i=0; i<word.length(); i++) {
                char temp = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word, level+1});
                        mp[word] = level+1;
                        st.erase(word);
                    }
                }
                word[i] = temp;
            }
        }

        // step 2: backtrack from the last word to find the possible sequences 

        vector<vector<string>> ans;
        if(mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(ans, seq, endWord, mp, beginWord);
        }
        return ans;
    }
};