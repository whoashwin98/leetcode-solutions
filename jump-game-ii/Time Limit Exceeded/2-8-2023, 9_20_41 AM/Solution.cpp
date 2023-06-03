// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    void solve(vector<int>& nums, int ans, int& minAns, int i) {
        if(i > nums.size() - 1) return;
        if(i == nums.size() - 1) {
            minAns = min(minAns, ans);
            return;
        }
        int num = nums[i];
        for(int j = num; j >= 1; j--) {
            cout << num << " " << ans << " " << minAns << " " << i << endl;
            solve(nums, ans+1, minAns, i+j);
        }
    }

    int jump(vector<int>& nums) {
        int ans = 0;
        int minAns = INT_MAX;
        solve(nums, ans, minAns, 0);
        return minAns;
    }
};