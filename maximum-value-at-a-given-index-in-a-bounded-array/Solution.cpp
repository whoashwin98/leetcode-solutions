class Solution
{
public:
    bool isSafe(int n, int index, int maxSum, int a)
    {
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return (res - a) <= maxSum;
    }

    int maxValue(int n, int index, int maxSum)
    {
        // removing the maximum element since it is already considered
        maxSum -= n;

        // perform BS between 0 and maxSum
        int low = 0;
        int high = maxSum;

        while (low < high)
        {
            int mid = (low + high + 1) / 2;
            if (isSafe(n, index, maxSum, mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low + 1;
    }
};