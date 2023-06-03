// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class compare {
    public: 
    bool operator()(vector<int>& a, vector<int>& b) {
        return (a[0] + a[1]) > (b[0] + b[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                pq.push({nums1[i], nums2[j]});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty() && ans.size() < k) {
            vector<int> p = pq.top();
            pq.pop();
            ans.push_back(p);
        }

        return ans;
    }
};