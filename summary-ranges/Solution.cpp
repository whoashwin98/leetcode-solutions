class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int n = nums.size();

        if (n == 1)
            return {to_string(nums[0])};

        string range = "";
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && nums[i] + 1 != nums[i + 1])
            {
                range += to_string(nums[i]);
                ans.push_back(range);
                range = "";
                continue;
            }

            else if (i == n - 1)
            {
                range += to_string(nums[i]);
                ans.push_back(range);
                range = "";
                continue;
            }

            if (range == "")
            {
                range += to_string(nums[i]);
                range += "->";
            }
        }

        return ans;
    }
};