class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost, int base) {
        long long result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result += 1L * abs(nums[i] - base) * cost[i];
        return result;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        long long ans = 0;

        while(low < high) {
            int mid = low + (high-low) / 2;
            long long c1 = getCost(nums, cost, mid);
            long long c2 = getCost(nums, cost, mid + 1);

            ans = min(c1, c2);

            if(c1 > c2) low = mid+1;
            else high = mid;
        }

        return ans;
    }
};