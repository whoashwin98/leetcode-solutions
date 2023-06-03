// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> present(nums.size());

        for(int i=0; i<nums.size(); i++) present[nums[i]] = true;

        vector<int> ans;
        for(int i=1; i<=nums.size(); i++) {
            if(!present[i]) ans.push_back(i);
        }

        return ans;
    }
};