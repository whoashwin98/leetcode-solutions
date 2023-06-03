// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int N) {
        string ans = "";
        vector<pair<int,string>> roman = {
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
        };

        for(int i=12; i>=0; i--) {
            while (N >= roman[i].first) {
                ans += roman[i].second;
                N -= roman[i].first;
            }
        }

        return ans;
    }
};