// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp;

        for(char ch : p) mp[ch]++;

        int n = s.size();
        int m = p.size();
        
        int left = 0;
        int right = m-1;

        while(left<=n-m) {
            unordered_map<char, int> chars(mp);
            int j = left;
            while(j <= right) {
                chars[s[j]]--;
                if(chars[s[j]] == 0) chars.erase(s[j]);
                j++;
            }
            
            if(chars.empty()) ans.push_back(left);
            left++;
            right++;
        }

        return ans;
    }
};