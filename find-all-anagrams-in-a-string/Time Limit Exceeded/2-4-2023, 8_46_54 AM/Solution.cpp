// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp;

        for(char ch : p) mp[ch]++;

        int n = s.size();
        int m = p.size();

        for(int i=0; i<=n-m; i++) {
            string str = s.substr(i,m);
            unordered_map<char, int> chars(mp);

            for(int j=0; j<str.size(); j++) {
                chars[str[j]]--;
                if(chars[str[j]] == 0) chars.erase(str[j]);
            }

            if(chars.empty()) ans.push_back(i);
        }

        return ans;
    }
};