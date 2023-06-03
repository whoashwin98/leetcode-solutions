// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        
        for(int i=0; i<nums.size(); i++) {
            if(us.find(nums[i]) == us.end()) {
                us.insert(nums[i]);
            }
            
            else {
                return nums[i];
            }
        }
        
        return -1;
    }
};