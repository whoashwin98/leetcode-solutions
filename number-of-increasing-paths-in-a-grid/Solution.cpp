class Solution
{
public:
    int mod = 1e9 + 7;

    int solve(vector<vector<int>> &grid, int n, int m, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int count = 0;
        int l = 0, r = 0, u = 0, d = 0;

        if (j >= 1 && grid[i][j - 1] > grid[i][j])
            l = 1 + solve(grid, n, m, i, j - 1, dp);

        if (j < m - 1 && grid[i][j + 1] > grid[i][j])
            r = 1 + solve(grid, n, m, i, j + 1, dp);

        if (i >= 1 && grid[i - 1][j] > grid[i][j])
            u = 1 + solve(grid, n, m, i - 1, j, dp);

        if (i < n - 1 && grid[i + 1][j] > grid[i][j])
            d = 1 + solve(grid, n, m, i + 1, j, dp);

        count += l + r + u + d;
        count = count % mod;
        return dp[i][j] = count;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>> dp(1001, vector<int>(1001, -1));

        // as we can start from any cell , therefore we will traverse over the whole grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                count += solve(grid, n, m, i, j, dp);
                count %= mod;
            }
        }

        return count + (n * m);
    }
};