// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> present(nums.size()+1,0);

        for(int num : nums) present[num]++;

        vector<int> ans;
        for(int i=1; i<=nums.size(); i++) {
            if(present[i] > 1) ans.push_back(i);
        }

        return ans;
    }
};