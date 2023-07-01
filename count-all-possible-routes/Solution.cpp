class Solution {
public:
    // recursion + memoization solution here
    int solve(vector<int>& locations, int i, int finish, int fuel, vector<vector<int>>& dp) {
        // base cases
        if(fuel < 0) return 0;

        if(dp[i][fuel] != -1) return dp[i][fuel];
        
        int count = (i == finish) ? 1 : 0;

        for(int j=0; j<locations.size(); j++) {
            if(j != i) {
                count = (count + solve(locations, j, finish, fuel - abs(locations[i] - locations[j]), dp)) % 1000000007;
            }
        }       

        return dp[i][fuel] = count;
    }


    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        // vector<vector<int>> dp(n, vector<int>(201, -1));
        // return solve(locations, start, finish, fuel, dp);

        // tabulation solution here
        vector<vector<int>> dp(n, vector<int>(201, 0));
        
        // base case
        for(int i=0; i<=fuel; i++) dp[finish][i] = 1;

        int ans = 0;
        for(int j=0; j<=fuel; j++) {
            for(int i=0; i<n; i++) {
                for(int k=0; k<n; k++) {
                    if(k == i) continue;
                    if(j - abs(locations[i] - locations[k]) >= 0) {
                        dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) % 1000000007;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
};