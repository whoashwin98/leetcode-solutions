// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string orig = s1;
        do {
            if(s2.find(s1) != -1) return true;
            next_permutation(s1.begin(),s1.end());
        } while (orig != s1);
        
        return false;
    }
};