// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<bool> vis(n+1,false);
        for(int i=0; i<nums.size(); ) {
            if(!vis[nums[i]]) {
                vis[nums[i]] = true;
                ans++;
                i++;
            }

            else {
                nums.erase(nums.begin() + i);
            }
        }
        
        return ans;
    }
};