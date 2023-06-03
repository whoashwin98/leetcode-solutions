// https://leetcode.com/problems/find-the-divisibility-array-of-a-string

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        int remainder = 0;
        vector<int> div(n, 0);
        for (int i = 0; i < n; i++) {
            remainder = (remainder * 10 + (word[i] - '0')) % m;
            if (remainder == 0) {
                div[i] = 1;
            }
        }
        return div;
    }
};