// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;

        int zeros = 0;

        for(int i=0; i<n && zeros <= 1; i++) {
            if(nums[i] == 0) zeros++;
            else prefix *= nums[i];
        }

        vector<int> ans;

        if(zeros > 1) {
            vector<int> res(n,0);
            return res;
        }

        else if(zeros == 1) {
            for(int i=0; i<n; i++) {
                if(nums[i] == 0) ans.push_back(prefix);
                else ans.push_back(0);
            }
            return ans;
        }

        else {
            for(int i=0; i<n; i++) {
                ans.push_back(prefix/nums[i]);
            }
            return ans;
        }
    }
};