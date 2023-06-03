// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    int findMax(vector<int> nums, int l, int r) {
        int ans = INT_MIN;
        for(int i=l; i<=r; i++) {
            ans = max(ans,nums[i]);
        }
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k-1;
        vector<int> ans;

        while(r < nums.size()) {
            int maxEle = findMax(nums,l,r);
            ans.push_back(maxEle);
            l++;
            r++;
        }

        return ans;
    }
};