// https://leetcode.com/problems/count-ways-to-build-good-strings

class Solution {
public:
    int solve(int zero, int one, int i) {
        if(i < 0) return 0;
        if(i == 0) return 1;

        int zeros = solve(zero, one, i-zero);
        int ones = solve(zero, one, i-one);

        return zeros + ones;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        for(int i = low; i<=high; i++) {
            ans += solve(zero, one, i);
        }
        return ans;
    }
};