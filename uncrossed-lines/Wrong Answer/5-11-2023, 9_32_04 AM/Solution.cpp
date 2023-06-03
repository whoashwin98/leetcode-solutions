// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == 0 && j == 0) return nums1[i] == nums2[j];
        if(i < 0 || j < 0) return -1e9;

        int dontPick = max(solve(nums1, nums2, i, j-1), solve(nums1, nums2, i-1, j));
        int pick = -1e9;
        if(nums1[i] == nums2[j]) pick = 1 + solve(nums1, nums2, i-1, j-1);

        return max(pick, dontPick);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2, nums1.size()-1, nums2.size()-1);
    }
};