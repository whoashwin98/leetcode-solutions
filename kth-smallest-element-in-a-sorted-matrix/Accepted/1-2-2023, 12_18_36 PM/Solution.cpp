// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;

        for(auto row : matrix) {
            for(int ele : row) {
                nums.push_back(ele);
            }
        }

        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};