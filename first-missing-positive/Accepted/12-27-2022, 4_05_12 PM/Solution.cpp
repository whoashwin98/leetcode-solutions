// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> us;
        int n = nums.size();

        int mini = INT_MAX;

        for(int i=0; i<n; i++) {
            us.insert(nums[i]);
            mini = min(mini, nums[i]);
        }

        int counter = 1;
        for(int ele : us) {
            if(ele <= 0) continue;
            if(ele == counter) counter++;
            else break;
        }

        return counter;
    }
};