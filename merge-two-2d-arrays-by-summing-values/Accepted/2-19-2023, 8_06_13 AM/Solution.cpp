// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        
        int a = 0, b = 0;
        int m = nums1.size(), n = nums2.size();
        
        while(a < m && b < n) {
            if(nums1[a][0] == nums2[b][0]) {
                ans.push_back({nums1[a][0], nums1[a][1] + nums2[b][1]});
                a++; b++;
            }
            
            else if(nums1[a][0] < nums2[b][0]) {
                ans.push_back(nums1[a++]);
            }
            
            else ans.push_back(nums2[b++]);
        }
        
        while(a < m) ans.push_back(nums1[a++]);
        while(b < n) ans.push_back(nums2[b++]);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};