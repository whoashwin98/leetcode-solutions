// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> us;
        int dup;
        
        for (int i=0; i < nums.size(); i++)
        {
            if(us.find(nums[i]) == us.end())
            {
                us.insert(nums[i]);
            }
            
            else
            {
                dup = nums[i];
            }
        }
        
        return dup;
    }
};
