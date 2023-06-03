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
        set<int> pq;
        for(int i=0; i<k; i++) pq.insert(nums[i]);

        while(r < nums.size()) {
            pq.insert(nums[r]);

            int maxEle = *pq.rbegin();
            ans.push_back(maxEle);
            
            auto it = pq.find(nums[l]);
            pq.erase(it);
            
            l++;
            r++;
        }

        return ans;
    }
};