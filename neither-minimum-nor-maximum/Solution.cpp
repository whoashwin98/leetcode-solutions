class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] == nums[n - 1])
            return -1;
        return nums[1];
    }
};