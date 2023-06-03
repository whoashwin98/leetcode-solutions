// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        while(i<m && j<n) {
            if(nums1[i] <= nums2[j]) {
                i++;
            }
            
            else {
                swap(nums1[i],nums2[j]);
                i++;
                j++;
            }
        }
        
        j=0;
        while(j<n) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};