// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1, mp2;

        for(int i=0; i<nums1.size(); i++) mp1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) mp2[nums2[i]]++;

        unordered_set<int> ans1;
        for(int i=0; i<nums1.size(); i++) {
            if(mp1.find(nums1[i]) != mp1.end() && mp2.find(nums1[i]) == mp2.end()) 
                ans1.insert(nums1[i]);
        }
        vector<int> a1;
        for(auto it : ans1) a1.push_back(it);

        unordered_set<int> ans2;
        for(int i=0; i<nums2.size(); i++) {
            if(mp2.find(nums2[i]) != mp2.end() && mp1.find(nums2[i]) == mp1.end()) 
                ans2.insert(nums2[i]);
        }
        vector<int> a2;
        for(auto it : ans2) a2.push_back(it);

        vector<vector<int>> res;
        res.push_back(a1);
        res.push_back(a2);
        return res;
    }
};