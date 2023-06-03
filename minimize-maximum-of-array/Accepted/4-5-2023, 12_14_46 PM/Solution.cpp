// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:
    bool isSafe(vector<int>& nums, int maxi) {
        long ex = 0;
        for (int i : nums) {
            if (i > maxi) {
                long c = (i - maxi);
                if (c > ex) return false;
                ex -= c;
            } else {
                ex += (maxi - i);
            }
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low) / 2;
            if(isSafe(nums, mid)) {
                ans = mid;
                high = mid-1;
            }

            else low = mid+1;
        }

        return ans;
    }
};