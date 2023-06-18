class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto word: wordList) {
            st.insert(word);
        }

        // if end word does not exist in the list we can stop here itself
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        while(!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord) return level;

            for(int i=0; i<word.length(); i++) {
                char temp = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i] = temp;
            }
        }

        return 0;
    }
};