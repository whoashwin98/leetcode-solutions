class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int d = arr[1] - arr[0];
        int a = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] != (a + (i * d)))
                return false;
        }

        return true;
    }
};