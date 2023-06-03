// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    int findMax(queue<int> q) {
        int ans = INT_MIN;
        while(!q.empty()) {
            ans = max(ans,q.front());
            q.pop();
        }
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k-1;
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<k-1; i++) q.push(nums[i]);

        while(r < nums.size()) {            
            q.push(nums[r]);

            int maxEle = findMax(q);
            ans.push_back(maxEle);

            l++;
            r++;
            q.pop();
        }

        return ans;
    }
};