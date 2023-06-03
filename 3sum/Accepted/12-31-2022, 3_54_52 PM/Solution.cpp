// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]] = i;

        for(int i=0; i<nums.size() - 2; i++) {
            if(nums[i] > 0) break; 
            
            int target = 0 - nums[i];
            for(int j = i+1; j<nums.size()-1; j++) {
                int third = target - nums[j];                
                if(mp.find(third) != mp.end() && mp[third] > j)
                {
                    res.push_back({nums[i], nums[j], third});
                }
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
        }

        return res;
    }
};