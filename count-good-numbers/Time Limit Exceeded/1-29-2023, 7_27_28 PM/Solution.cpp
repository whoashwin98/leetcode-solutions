// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    const int M = 1000000007;

    void solve(long long n, long long int& ans) {
        if(n < 0) return;
        if(n & 1) ans = (ans%M * 4) % M;
        else ans = (ans%M * 5) % M;
        solve(n-1,ans);
    }

    int countGoodNumbers(long long n) {
        long long int ans = 1;
        solve(n-1, ans);
        return (int)ans;
    }
};