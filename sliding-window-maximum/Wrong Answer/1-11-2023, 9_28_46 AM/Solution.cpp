// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    void pushInQueue(deque<int>& dq, int val) {
        while(!dq.empty() && dq.back() <= val) dq.pop_back();
        dq.push_back(val);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int left = 0;

        for(int i=0; i<nums.size(); i++) {
            pushInQueue(dq,nums[i]);
            
            if(left == i-k && nums[left] == dq.front()) dq.pop_front();

            if(i >= k-1) {
                ans.push_back(dq.front());
                left++;
            }
        }

        return ans;
    }
};