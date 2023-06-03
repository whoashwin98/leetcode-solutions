// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int first = 0;
        int second = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_set<int> mp;

        vector<int> ans;
        while(first < nums1.size() && second < nums2.size()) {
            if(nums1[first] == nums2[second] && mp.find(nums2[second]) == mp.end()) {
                ans.push_back(nums1[first]);
                mp.insert(nums1[first]);
                first++;
                second++;
            }

            else if(nums1[first] < nums2[second]) first++;
            else second++;
        }

        return ans;
    }
};