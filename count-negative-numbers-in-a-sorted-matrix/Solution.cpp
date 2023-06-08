class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int limit = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int j = m - 1;
            while (j >= limit && grid[i][j] < 0)
            {
                ans++;
                j--;
            }

            limit = j + 1;
        }

        return ans;
    }
};