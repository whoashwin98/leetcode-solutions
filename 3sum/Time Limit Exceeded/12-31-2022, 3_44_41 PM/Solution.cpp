// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        for(int i=0; i<nums.size() - 1; i++) {
            int target = 0 - nums[i];
            unordered_map<int,int> mp;
            
            for(int j = i+1; j<nums.size(); j++) {
                if(mp.find(target - nums[j]) != mp.end()) {
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[mp[target - nums[j]]]);
                    sort(ans.begin(), ans.end());
                    auto it = find(res.begin(), res.end(), ans);
                    if(it == res.end()) res.push_back(ans);
                }

                mp[nums[j]] = j;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};