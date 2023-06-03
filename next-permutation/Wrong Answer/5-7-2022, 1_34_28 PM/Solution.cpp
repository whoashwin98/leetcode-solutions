// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i,j;
    bool flag = false;
    for(i=n-2; i>=0; i--) {
        if(nums[i] < nums[i+1]){
            flag = true;
            break;
        } 
            
    }

    if(!flag) {
        reverse(nums.begin(),nums.end());
        return;
    }
    else {
        j=i+1;
        for(j=i+1; j<n; j++) {
            if(nums[i] < nums[j]) break;
        }
            
        swap(nums[i], nums[j]);

        reverse(nums.begin()+i+1,nums.end());
    }
    }
};