class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();
        if (n <= 2)
            return true;

        double x1 = coordinates[0][0];
        double y1 = coordinates[0][1];
        double x2 = coordinates[1][0];
        double y2 = coordinates[1][1];
        double slope = (x1 != x2) ? (y2 - y1) / (x2 - x1) : INT_MAX;

        for (int i = 2; i < n; i++)
        {
            x1 = coordinates[i - 1][0];
            y1 = coordinates[i - 1][1];
            x2 = coordinates[i][0];
            y2 = coordinates[i][1];

            double currSlope = x1 != x2 ? (y2 - y1) / (x2 - x1) : INT_MAX;
            if (currSlope != slope)
                return false;
        }

        return true;
    }
};