// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;

        for(int i=0; i<order.size(); i++) {
            mp[order[i]] = i;
        }

        for(int i=0; i<words.size()-1; i++) {
            string first = words[i];
            string second = words[i+1];
            if(mp[first[0]] < mp[second[0]]) continue;

            int a=0, b=0;
            while(a < first.size() && b < second.size() && first[a] == second[b]) { a++; b++; }
            if(b == second.size() && a < first.size()) return false;
            if(mp[first[a]] > mp[second[b]]) return false;
        }

        return true;
    }
};