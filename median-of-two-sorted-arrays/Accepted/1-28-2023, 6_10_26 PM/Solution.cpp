// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    vector<int> mergeSorted(vector<int> nums1, vector<int> nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans(m+n);
        int i=0, j=0, k=0;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                ans[k++] = nums1[i++];
            }

            else {
                ans[k++] = nums2[j++];
            }
        }

        while(i < m) {
            ans[k++] = nums1[i++];
        }

        while(j < n) {
            ans[k++] = nums2[j++];
        }

        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = mergeSorted(nums1, nums2);
        int size = ans.size();

        if(size & 1) return ans[size/2];
        else {
            double res = (ans[size/2-1] + ans[size/2]) / 2.0;
            return res;
        }
    }
};