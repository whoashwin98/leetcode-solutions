// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class compare {
    public: 
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return (a.first + a.second) > (b.first + b.second);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                pq.push({nums1[i], nums2[j]});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty() && ans.size() < k) {
            pair<int,int> p = pq.top();
            pq.pop();
            vector<int> res;
            res.push_back(p.first);
            res.push_back(p.second);
            ans.push_back(res);
        }

        return ans;
    }
};