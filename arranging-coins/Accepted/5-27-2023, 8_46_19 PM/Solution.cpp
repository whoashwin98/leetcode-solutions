// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        int steps = 0;
        for(int i=1; i < INT_MAX; i++) {
            if(n < i) break;
            n -= i;
            steps++;
        }
        return steps;
    }
};