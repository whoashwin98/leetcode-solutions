class Solution
{
public:
    // can be done using "upper_bound", implemented it just to explain clearly
    int getBigger(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
            {
                ans = nums[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
    int solve(vector<int> &nums1, vector<int> &nums2, int currIdx, int prev, map<pair<int, int>, int> &dp)
    {
        if (currIdx == nums1.size())
            return 0;

        if (dp.count({currIdx, prev}))
            return dp[{currIdx, prev}];

        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        int newCurr = nums1[currIdx], curr = nums1[currIdx];

        if (nums1[currIdx] <= prev)
        {
            newCurr = getBigger(nums2, prev); // get a "just" bigger value than prev
            if (newCurr > prev)
                x = solve(nums1, nums2, currIdx + 1, newCurr, dp);
            if (x != INT_MAX)
                x++;
        }

        else
        {
            y = solve(nums1, nums2, currIdx + 1, curr, dp); // don't change curr, no operation done
            newCurr = getBigger(nums2, prev);               // get a "just" bigger value than prev
            if (newCurr > prev)
                z = solve(nums1, nums2, currIdx + 1, newCurr, dp);
            if (z != INT_MAX)
                z++;
        }

        return dp[{currIdx, prev}] = min({x, y, z});
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        int m = arr1.size();
        int n = arr2.size();

        map<pair<int, int>, int> dp;
        int ans = solve(arr1, arr2, 0, -1, dp);
        return (ans == INT_MAX ? -1 : ans);
    }
};