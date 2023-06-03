// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;

        for(int i=0; i<nums.size() - 3; i++) {
            for(int j=i+1; j<nums.size() - 2; j++) {
                
                int rem = target - nums[i] - nums[j];
                int l = j+1;
                int r = nums.size()-1;

                while(l < r) {
                    if(nums[l] + nums[r] == rem) {
                        st.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }

                    else if(nums[l] + nums[r] < rem) l++;
                    else r--;
                }
            }
        }

        for(auto v : st) ans.push_back(v);
        return ans;
    }
};