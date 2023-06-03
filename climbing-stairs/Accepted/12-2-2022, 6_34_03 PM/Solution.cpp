// https://leetcode.com/problems/climbing-stairs

class Solution {
public:

    int climbStairs(int n) {
        vector<int> fib(46,0);
        fib[0] = 1;
        fib[1] = 1;
        for(int i=2; i<=45; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
};