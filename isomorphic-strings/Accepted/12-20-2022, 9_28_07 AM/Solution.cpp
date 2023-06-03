// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> type;
        int currType = 0;
        string typeOfS = "";

        for(char ch : s) {
            if(type.find(ch) == type.end()) {
                currType++;
                type[ch] = currType;
            }
            typeOfS.push_back(type[ch] + '0');
        }

        type.clear();
        string typeOfT = "";
        currType = 0;
        for(char ch : t) {
            if(type.find(ch) == type.end()) {
                currType++;
                type[ch] = currType;
            }
            typeOfT.push_back(type[ch] + '0');
        }

        return typeOfS == typeOfT;
    }
};