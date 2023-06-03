// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int solve(vector<int> coins, int amt, int i) {
        // base case
        if(amt == 0) return 1;
        if(i < 0) return 0;

        int dontPick = solve(coins, amt, i-1);
        int pick = 0;
        if(coins[i] <= amt) pick = solve(coins, amt-coins[i], i);
        return pick + dontPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(coins, amount, n-1);
    }
};