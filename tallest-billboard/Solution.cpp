class Solution {
public:
    // recursion with 3 variables
    int solve(vector<int> rods, int n, int i, int sum1, int sum2) {
        if(i == n) {
            if(sum1 == sum2) return sum1;
            return INT_MIN;
        } 

        int inc_sum1 = solve(rods, n, i+1, sum1 + rods[i], sum2);
        int inc_sum2 = solve(rods, n, i+1, sum1, sum2 + rods[i]);
        int not_inc = solve(rods, n, i+1, sum1, sum2);

        return max(not_inc, max(inc_sum1, inc_sum2));
    }

    // recursion with 2 variables + memoization
    int solve(vector<int> rods, int n, int i, int diff, vector<vector<int>>& dp) {
        if(i == n) {
            if(!diff) return 0;
            return -1e9;
        } 

        if(dp[i][diff + 5000] != -1) return dp[i][diff + 5000];

        int inc_sum1 = rods[i] + solve(rods, n, i+1, diff + rods[i], dp);
        int inc_sum2 = solve(rods, n, i+1, diff - rods[i], dp);
        int not_inc = solve(rods, n, i+1, diff, dp);

        return dp[i][diff + 5000] = max(not_inc, max(inc_sum1, inc_sum2));
    }

    int dp[21][10001];
    int helper(vector<int>& rods, int set, int idx) {
        if(idx == rods.size()) {
            if(set == 0) return 0;
            return INT_MIN;
        }
        if(dp[idx][set+5000] != -1) return dp[idx][set+5000];    // adding 5000, sothat index not become -ve

        int case1 = helper(rods, set, idx+1);               // ignoring the rod
        int case2 = rods[idx] + helper(rods, set+rods[idx], idx+1);   // taking rod in set1
        int case3 = helper(rods, set-rods[idx], idx+1);     // taking rod in set2

        return dp[idx][set+5000] = max({case1, case2, case3});
    }


    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        return helper(rods, 0, 0);
    }
};