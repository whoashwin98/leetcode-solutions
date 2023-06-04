class Solution
{
public:
    int semiOrderedPermutation(vector<int> &nums)
    {
        int oneIdx = 0;
        int nIdx = 0;
        int n = nums.size();

        if (nums[0] == 1 && nums[n - 1] == n)
            return 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                oneIdx = i;
            }

            else if (nums[i] == n)
            {
                nIdx = i;
            }
        }

        if (nIdx < oneIdx)
        {
            oneIdx--;
        }

        int ans = oneIdx + (n - 1 - nIdx);
        return ans;
    }
};